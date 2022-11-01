namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable ptr = -1;
            for (i in 0 .. Length(qs)-1) {
                if (bits0[i] && bits1[i]) {
                    X(qs[i]);
                } elif (!bits0[i] && !bits1[i]) {
                } elif (ptr == -1) {
                    H(qs[i]);
                    set ptr = i;
                } elif (bits0[i]) {
                    if (bits1[ptr]) {
                        X(qs[ptr]);
                    }
                    CNOT(qs[ptr], qs[i]);
                    if (bits1[ptr]) {
                        X(qs[ptr]);
                    }
                } elif (bits1[i]) {
                    if (bits0[ptr]) {
                        X(qs[ptr]);
                    }
                    CNOT(qs[ptr], qs[i]);
                    if (bits0[ptr]) {
                        X(qs[ptr]);
                    }
                }
            }
        }
    }
}