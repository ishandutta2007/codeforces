namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable ans = new Int[N];
            using (qs = Qubit[N + 1]){
                ResetAll(qs);
                X(qs[N]);
                for (i in 0 .. N){
                    H(qs[i]);
                }
                Uf(qs[0 .. N - 1], qs[N]);
                for (i in 0 .. N - 1){
                    H(qs[i]);
                }
                for (i in 0 .. N - 1){
                    if (M(qs[i]) == One){
                        set ans[i] = 1;
                    }
                    else{
                        set ans[i] = 0;
                    }
                }
                ResetAll(qs);
            }
            return ans;
        }
    }
}