namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            if (bits[0]) {
                H(qs[0]);
            }
            for (i in 1 .. Length(qs)-1) {
                if (bits[i]) {
                    if (bits[0] == false) {
                        X(qs[0]);
                    }
                    CNOT(qs[0], qs[i]);
                    if (bits[0] == false) {
                        X(qs[0]);
                    }
                }
            }
        }
    }
}