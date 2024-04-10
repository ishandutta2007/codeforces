namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable answer = 1;
        using (tmp = Qubit[2]) {
            unitary(tmp);
            if (M(tmp[1]) == One) {
                set answer = 0;
                X(tmp[1]);
            }
        }
        return answer;
    }
}