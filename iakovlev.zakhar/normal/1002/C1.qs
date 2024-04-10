namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(0.35, q);
            if (M(q) == Zero) {
                return 0;
            } else {
                return 1;
            }
        }
    }
}