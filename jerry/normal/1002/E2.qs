namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve(N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable result = new Int[N];
            for (i in 0..N-1) {
                set result[i] = 1;
            }
            using (qs = Qubit[N+1])
            {
                Uf(qs[0..(N-1)], qs[N]);
                if (M(qs[N]) == One) {
                    set result[0] = 0;
                }
                for (i in 0..N) {
                    Reset(qs[i]);
                }
            }
            return result;
        }
    }
}