namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable x = -1;
            for (i in 0 .. Length(qs) - 1) {
                if (bits0[i] && bits1[i]) {
                    X(qs[i]);
                }
                if ((bits0[i] || bits1[i]) && (!(bits0[i] && bits1[i]))) {
                    if (x < 0) {
                        set x = i;
                        H(qs[i]);
                    } else {
                        CNOT(qs[x], qs[i]);
                        if ((bits0[x] && bits1[i]) ||(bits0[i] && bits1[x])) {
                            X(qs[i]);
                        }
                    }
                }
            }
        }
    }
}