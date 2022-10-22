namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable ans = -1;
            using (x = Qubit[1]) {
                H(x[0]);
                if (M(x[0]) == One) {
                    if (M(q) == One) {
                        set ans = 1;
                    }
                } else {
                    H(q);
                    if (M(q) == One) {
                        set ans = 0;
                    }
                }
                Reset(x[0]);
            }
            return ans;
        }
    }
}