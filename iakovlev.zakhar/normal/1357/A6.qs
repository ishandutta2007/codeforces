namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = -1;
        using (x = Qubit[2]) {
            H(x[0]);
            CNOT(x[0], x[1]);
            unitary(x[1]);
            CNOT(x[1], x[0]);
            H(x[1]);
            if (M(x[0]) == One) {
                if (M(x[1]) == One) {
                    set ans = 2;
                } else {
                    set ans = 1;
                }
            } else {
                if (M(x[1]) == One) {
                    set ans = 3;
                } else {
                    set ans = 0;
                }
            }
            Reset(x[0]);
            Reset(x[1]);
        }
        return ans;
    }
}