namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        using (aux = Qubit()) {
            repeat {
                H(qs[0]);
                H(qs[1]);
                Controlled X(qs, aux);
            } until (M(aux) == Zero)
            fixup {
                X(qs[0]);
                X(qs[1]);
                X(aux);
            }
        }
        X(qs[0]);
        X(qs[1]);
    }
}