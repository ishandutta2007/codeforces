namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            Controlled Z([qs[0]], qs[1]);
            H(qs[0]);
            H(qs[1]);
            let b1 = M(qs[0]);
            let b2 = M(qs[1]);
            mutable result = 0;
            if (b1 == Zero) {
                set result += 1;
            }
            if (b2 == Zero) {
                set result += 2;
            }
            return result;
        }
    }
}