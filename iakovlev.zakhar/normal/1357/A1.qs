namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = -1;
        using(x = Qubit[2]) {
            X(x[0]);
            X(x[1]);
            unitary(x);
            if (M(x[0]) == One) {
                set ans = 0;
            } else {
                set ans = 1;
            }
            Reset(x[0]);
            Reset(x[1]);
        }
        return ans;
    }
}