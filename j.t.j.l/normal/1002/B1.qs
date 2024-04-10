namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            for (i in 1 .. Length(qs) - 1){
                CNOT(qs[i - 1], qs[i]);
            }
            if (M(qs[Length(qs)-1]) != One){
                return 0;
            }
            return 1;
        }
    }
}