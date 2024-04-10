namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            using((x, y) = (Qubit[N], Qubit())) {
                mutable b = new Int[0];
                Uf(x, y);
                if (M(y) == One) {
                    if (N % 2 == 0) {
                        set b += [1];
                    } else {
                        set b += [0];
                    }
                } else {
                    if (N % 2 == 0) {
                        set b += [0];
                    } else {
                        set b += [1];
                    }
                }

                for (i in 0..N-2) {
                    set b += [0];
                }

                for (q in x) {
                    Reset(q);
                }
                Reset(y);

                return b;
            }
        }
    }
}