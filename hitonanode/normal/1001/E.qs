namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // your code here
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            return ResultArrayAsInt([M(qs[0]), M(qs[1])]);
        }
    }
}