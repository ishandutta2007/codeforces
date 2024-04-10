
 namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        if (n == 2) {
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            CNOT(qs[0], qs[1]);
        }
        if (n == 3) {
            CCNOT(qs[0], qs[2], qs[1]);
            X(qs[0]);
            X(qs[2]);
            CCNOT(qs[0], qs[2], qs[1]);
            X(qs[0]);
            X(qs[2]);
            for (i in 1 .. Length(qs) - 1) {
                CNOT(qs[0], qs[i]);
            }
            H(qs[0]);
            for (i in 1 .. Length(qs) - 1) {
                CNOT(qs[0], qs[i]);
            }
        }
        if (n == 4) {
            CCNOT(qs[0], qs[3], qs[1]);
            CCNOT(qs[0], qs[3], qs[2]);
            X(qs[0]);
            X(qs[3]);
            CCNOT(qs[0], qs[3], qs[1]);
            CCNOT(qs[0], qs[3], qs[2]);
            X(qs[0]);
            X(qs[3]);
            X(qs[0]);
            (Controlled X)([qs[0], qs[1], qs[3]], qs[2]);
            X(qs[0]);
            X(qs[1]);
            X(qs[3]);
            (Controlled X)([qs[0], qs[1], qs[3]], qs[2]);
            X(qs[1]);
            X(qs[3]);
            for (i in 1 .. Length(qs) - 1) {
                CNOT(qs[0], qs[i]);
            }
            H(qs[0]);
            for (i in 1 .. Length(qs) - 1) {
                CNOT(qs[0], qs[i]);
            }
        }
        if (n == 5) {
            CCNOT(qs[0], qs[4], qs[1]);
            CCNOT(qs[0], qs[4], qs[2]);
            CCNOT(qs[0], qs[4], qs[3]);
            X(qs[0]);
            X(qs[4]);
            CCNOT(qs[0], qs[4], qs[1]);
            CCNOT(qs[0], qs[4], qs[2]);
            CCNOT(qs[0], qs[4], qs[3]);
            X(qs[0]);
            X(qs[4]);
            
            X(qs[1]);
            X(qs[4]);
            (Controlled X)([qs[0], qs[1], qs[4]], qs[2]);
            (Controlled X)([qs[0], qs[1], qs[4]], qs[3]);
            X(qs[4]);
            X(qs[1]);
            X(qs[0]);
            X(qs[1]);
            X(qs[4]);
            X(qs[1]);
            X(qs[4]);
            (Controlled X)([qs[0], qs[1], qs[4]], qs[2]);
            (Controlled X)([qs[0], qs[1], qs[4]], qs[3]);
            X(qs[4]);
            X(qs[1]);
            X(qs[0]);
            X(qs[1]);
            X(qs[4]);
            
            X(qs[2]);
            X(qs[4]);
            (Controlled X)([qs[0], qs[1], qs[2], qs[4]], qs[3]);
            X(qs[2]);
            X(qs[4]);
            X(qs[0]);
            X(qs[1]);
            X(qs[2]);
            X(qs[4]);
            X(qs[2]);
            X(qs[4]);
            (Controlled X)([qs[0], qs[1], qs[2], qs[4]], qs[3]);
            X(qs[2]);
            X(qs[4]);
            X(qs[0]);
            X(qs[1]);
            X(qs[2]);
            X(qs[4]);
            
            for (i in 1 .. Length(qs) - 1) {
                CNOT(qs[0], qs[i]);
            }
            H(qs[0]);
            for (i in 1 .. Length(qs) - 1) {
                CNOT(qs[0], qs[i]);
            }
        }
    }
}