namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = -1;
        using (x = Qubit[2]) {
            H(x[0]);
            CNOT(x[0], x[1]);
            (Controlled unitary)([x[0]], x[1]);
            (Controlled Z)([x[0]], x[1]);
            CNOT(x[0], x[1]);
            H(x[0]);
            if (M(x[0]) == One) {
                set ans = 1;
            } else {
                set ans = 0;
            }
            Reset(x[0]);
            Reset(x[1]);
        }
        return ans;
    }
}