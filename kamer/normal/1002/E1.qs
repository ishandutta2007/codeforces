namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            using ((x, y) = (Qubit[N], Qubit())) {
                mutable b = new Int[0];
                for (q in x) {
                    H(q);
                }
                X(y);
                H(y);
                Uf(x, y);
                H(y);
                // M(y);
                for (q in x) {
                    H(q);
                }
                for (i in 0..N-1) {
                    if (M(x[i]) == One) {
                        set b += [1];
                    } else {
                        set b += [0];
                    }
                }
                for (i in 0..N-1) {
                    Reset(x[i]);
                }
                Reset(y);
                return b;
            }
        }
    }
}