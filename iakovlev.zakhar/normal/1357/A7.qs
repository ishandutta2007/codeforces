namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = -1;
        using (x = Qubit[2]) {
            H(x[0]);
            CNOT(x[0], x[1]);
            (Controlled unitary)(x[0..0], x[1]);
            (Controlled unitary)(x[0..0], x[1]);
            CNOT(x[1], x[0]);
            H(x[1]);
            if (M(x[1]) == Zero) {
                Reset(x[0]);
                Reset(x[1]);
                H(x[0]);
                CNOT(x[0], x[1]);
                (Controlled unitary)(x[0..0], x[1]);
                (Controlled Y)(x[0..0], x[1]);
                CNOT(x[1], x[0]);
                H(x[1]);
                if (M(x[1]) == Zero) {
                    set ans = 0;
                } else {
                    set ans = 2;
                }
            } else {
                Reset(x[0]);
                Reset(x[1]);
                H(x[0]);
                CNOT(x[0], x[1]);
                (Controlled unitary)(x[0..0], x[1]);
                (Controlled X)(x[0..0], x[1]);
                (Controlled Z)(x[0..0], x[1]);
                CNOT(x[1], x[0]);
                H(x[1]);
                if (M(x[1]) == Zero) {
                    set ans = 3;
                } else {
                    set ans = 1;
                }
            }
            Reset(x[0]);
            Reset(x[1]);
        }
        return ans;
    }
}