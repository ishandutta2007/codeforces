namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            H(qs[0]);
            mutable pos = 0;
            if (bits0[0] == bits1[0]){
                for (i in 1 .. Length(qs) - 1){
                    if (bits0[i] != bits1[i]){
                        set pos = i;
                    }
                }
                CNOT(qs[0], qs[pos]);
                CNOT(qs[pos], qs[0]);
            }
            for (i in 0 .. Length(qs) - 1){
                if (i != pos){
                    if (bits0[i] != bits1[i]){
                        CNOT(qs[pos], qs[i]);
                    }
                    if (bits0[i] != false){
                        X(qs[i]);
                    }
                }
            }
            if (bits0[pos] != false){
                X(qs[pos]);
            }
        }
    }
}