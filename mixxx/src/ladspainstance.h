/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef LADSPAINSTANCE_H
#define LADSPAINSTANCE_H

#include <q3ptrlist.h>

#include <ladspa.h>

#include <defs.h>
#include <controlobject.h>

class LADSPAInstance {

public:
    LADSPAInstance(const LADSPA_Descriptor * descriptor);
    ~LADSPAInstance();

    void process(const CSAMPLE * pIn, const CSAMPLE * pOut, const int iBufferSize);
    void connect(unsigned long port, LADSPA_Data * buffer);

private:
    const LADSPA_Descriptor * m_pDescriptor;
    LADSPA_Handle m_Handle;
    unsigned long m_InputPort;
    unsigned long m_OutputPort;
    static ControlObject *m_pControlObjectSampleRate;
};

typedef Q3PtrList<LADSPAInstance> LADSPAInstanceList;

#endif
