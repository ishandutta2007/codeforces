namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            H(qs[1]);
            let a = M(qs[0]);
            let b = M(qs[1]);
            if (a == Zero) {
                if (b == Zero) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (b == Zero) {
                    return 2;
                } else {
                    return 3;
                }
            }
        }
    }
}