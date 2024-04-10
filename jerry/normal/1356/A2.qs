namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable answer = 0;
        using (tmp = Qubit()) {
            H(tmp);
            unitary(tmp);
            H(tmp);
            if (M(tmp) == One) {
                set answer = 1;
                X(tmp);
            }
        }
        return answer;
    }
}