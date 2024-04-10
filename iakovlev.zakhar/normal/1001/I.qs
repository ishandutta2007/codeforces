namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable ans = true;
            using((x,y) = (Qubit[N], Qubit())){
                ApplyToEach(H,x);
                X(y);
                H(y);
                Uf(x,y);
                ApplyToEach(H,x);
                H(y);
                for(i in 0 .. N-1){
                    if(M(x[i]) == One) 
                    {
                        set ans = false;
                    }
                }
                ResetAll(x);
                Reset(y);
            }
            return ans;
        }
    }
}