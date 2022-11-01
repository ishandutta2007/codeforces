namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            (Controlled X)([qs[1]], qs[0]);
            H(qs[1]);
            if (M(qs[0]) == One)
            {
                if (M(qs[1]) == One)
                {
                    return 0;
                }
                return 2;
            }
            if (M(qs[1]) == One)
            {
                return 1;
            }
            return 3;
        }
    }
}