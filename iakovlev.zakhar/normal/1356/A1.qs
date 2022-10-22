namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = -1;
        using(x = Qubit[1]) {
            unitary(x[0]);
            if (M(x[0]) == One) {
                set ans = 1;
            } else {
                set ans = 0;
            }
            Reset(x[0]);
        }
        return ans;
    }
}