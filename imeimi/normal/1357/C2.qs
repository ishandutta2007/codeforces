namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    operation Recursive(qs : Qubit[], q : Qubit, parity : Int, idx : Int) : Unit {
        if (idx == Length(qs)) {
            if (parity == 1) {
                Controlled X(qs, q);
            }
        }
        else {
            X(qs[idx]);
            Recursive(qs, q, parity, idx + 1);
            X(qs[idx]);
            Recursive(qs, q, parity ^^^ 1, idx + 1);
        }
    }
    operation Solve(qs : Qubit[], parity : Int) : Unit {
        using (q = Qubit()) {
            repeat {
                for (i in qs) { H(i); }
                Recursive(qs, q, parity, 0);
            }
            until (M(q) == Zero)
            fixup {
                ResetAll(qs);
                Reset(q);
            }
            Reset(q);
        }
    }
}