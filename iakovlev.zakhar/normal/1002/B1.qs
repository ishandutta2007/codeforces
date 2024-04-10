namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            for (i in 0 .. Length(qs) - 1) {
                for (j in 0 .. i - 1) {
                    CNOT(qs[i], qs[j]);
                }
            }
            if (M(qs[0]) == One) {
                return 1;
            }
            return 0;
        }
    }
}