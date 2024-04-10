namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            using((x, y) = (Qubit[N], Qubit())) {
                for (q in x) {
                    H(q);
                }
                X(y);
                H(y);
                Uf(x, y);
                for (q in x) {
                    H(q);
                }
                mutable result = true;
                for (q in x) {
                    if (M(q) == One) {
                        set result = false;
                    }
                }

                for (q in x) {
                    Reset(q);
                }
                Reset(y);
                return result;
            }
        }
    }
}