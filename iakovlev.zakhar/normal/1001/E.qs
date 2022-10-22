namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            if (M(qs[0]) == One) {
                if (M(qs[1]) == One) {
                    return 3;
                }
                return 1;
            }
            if (M(qs[1]) == One) {
                return 2;
            }
            return 0;
        }
    }
}