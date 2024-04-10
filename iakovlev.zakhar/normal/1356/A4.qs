namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = -1;
        using(x = Qubit[2]) {
            unitary(x);
            if (M(x[1]) == One) {
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