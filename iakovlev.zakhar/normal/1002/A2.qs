namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            mutable first = -1;
            for (i in 0 .. Length(bits) - 1) {
                if (bits[i]) {
                    set first = i;
                }
            }
            if (first >= 0) {
                H(qs[first]);
                for (i in 0 .. first - 1) {
                    if (bits[i]) {
                        CNOT(qs[first], qs[i]);
                    }
                }
            }
        }
    }
}