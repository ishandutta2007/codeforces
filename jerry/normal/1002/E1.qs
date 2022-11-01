namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve(N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable result = new Int[N];
            using (qs = Qubit[N+1])
            {
                X(qs[N]);
                for (i in 0..N) {
                    H(qs[i]);
                }
                Uf(qs[0..(N-1)], qs[N]);
                for (i in 0..N-1) {
                    H(qs[i]);
                    if (M(qs[i]) == One) {
                        set result[i] = 1;
                    }
                    Reset(qs[i]);
                }
                Reset(qs[N]);
            }
            return result;
        }
    }
}