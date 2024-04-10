namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            H(qs[1]);
            let b1 = M(qs[0]);
            let b2 = M(qs[1]);
            mutable result = 0;
            if (b1 == One) {
                set result = result + 2;
            }
            if (b2 == One) {
                set result = result + 1;
            }
            return result;
        }
    }
}