namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation ShiftBy1 (qs : Qubit[]) : Unit {
        let n = Length(qs);
        for (i in n-1 .. -1 .. 1) {
            Controlled X(qs[0..i-1], qs[i]);
        }
        X(qs[0]);
    }

    operation Solve (qs : Qubit[]) : Unit {
        for (i in 1 .. 2 ^ Length(qs) - 1) {
            Controlled H(Rest(qs), Head(qs));
            ShiftBy1(qs);
        }
        ShiftBy1(qs);
    }
}