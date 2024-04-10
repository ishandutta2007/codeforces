namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable answer = -1;
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            if (M(qs[0]) == Zero) {
                X(qs[1]);
                set answer = 3;
            } elif (M(qs[1]) == One) {
                X(qs[0]); X(qs[1]);
                set answer = 1;
            } else {
                X(qs[1]);
                unitary(qs);
                X(qs[1]);
                if (M(qs[0]) == Zero) {
                    set answer = 2;
                } else {
                    X(qs[0]);
                    set answer = 0;
                }
            }
        }
        return answer;
    }
}