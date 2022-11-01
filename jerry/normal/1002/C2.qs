namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable ans = -1;
            using (rng=Qubit[1])
            {
                H(rng[0]);
                if (MResetZ(rng[0]) == One)
                {
                    if (M(q) == One) {
                        set ans = 1;
                    }
                } else
                {
                    R(PauliY, 1.5707963267948966, q);
                    if (M(q) == Zero) {
                        set ans = 0;
                    }
                }
            }
            return ans;
        }
    }
}