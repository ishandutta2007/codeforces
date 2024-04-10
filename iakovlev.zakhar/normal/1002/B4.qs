namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            let res = M(qs[0]);
            let v = M(qs[1]);
            if (res == One) {
                if (v == One) {
                    return 0;
                }
                return 1;
            }
            if (v == One) {
                return 2;
            }
            return 3;
        }
    }
}