namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            for (i in 0 .. Length(qs)-2) {
                CNOT(qs[i], qs[i+1]);
            }
            if (M(qs[Length(qs)-1]) == Zero) {
                return 0;
            }
            return 1;
        }
    }
}