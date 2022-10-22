namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        if (n == 2) {
            (Controlled H)([qs[1]], qs[0]);
            (Controlled H)([qs[0]], qs[1]);
            X(qs[1]);
            (Controlled H)([qs[1]], qs[0]);
            X(qs[1]);
            CNOT(qs[1], qs[0]);
        }
        if (n == 3) {
            (Controlled H)([qs[2], qs[1]], qs[0]);
            (Controlled H)([qs[2], qs[0]], qs[1]);
            CNOT(qs[2], qs[1]);
            (Controlled H)([qs[2], qs[1]], qs[0]);
            CNOT(qs[2], qs[1]);
            CCNOT(qs[2], qs[1], qs[0]);
            
            CCNOT(qs[0], qs[2], qs[1]);
            (Controlled H)([qs[0], qs[1]], qs[2]);
            
            X(qs[2]);
            (Controlled H)([qs[2], qs[1]], qs[0]);
            (Controlled H)([qs[2], qs[0]], qs[1]);
            X(qs[1]);
            (Controlled H)([qs[2], qs[1]], qs[0]);
            X(qs[1]);
            CCNOT(qs[2], qs[1], qs[0]);
            X(qs[2]);
            
            CCNOT(qs[0], qs[2], qs[1]);
            CNOT(qs[2], qs[1]);
            CCNOT(qs[2], qs[1], qs[0]);
            CNOT(qs[2], qs[1]);
        }
        if (n == 4) {
            (Controlled H)([qs[3], qs[2], qs[1]], qs[0]);
            (Controlled H)([qs[3], qs[2], qs[0]], qs[1]);
            CCNOT(qs[3], qs[2], qs[1]);
            (Controlled H)([qs[3], qs[2], qs[1]], qs[0]);
            CCNOT(qs[3], qs[2], qs[1]);
            (Controlled X)([qs[3], qs[2], qs[1]], qs[0]);
            
            (Controlled X)([qs[3], qs[0], qs[2]], qs[1]);
            (Controlled H)([qs[3], qs[0], qs[1]], qs[2]);
            
            CNOT(qs[3], qs[2]);
            (Controlled H)([qs[3], qs[2], qs[1]], qs[0]);
            (Controlled H)([qs[3], qs[2], qs[0]], qs[1]);
            CNOT(qs[3], qs[1]);
            (Controlled H)([qs[3], qs[2], qs[1]], qs[0]);
            CNOT(qs[3], qs[1]);
            (Controlled X)([qs[3], qs[2], qs[1]], qs[0]);
            CNOT(qs[3], qs[2]);
            
            (Controlled X)([qs[3], qs[0], qs[2]], qs[1]);
            CCNOT(qs[3], qs[2], qs[1]);
            (Controlled X)([qs[3], qs[2], qs[1]], qs[0]);
            CCNOT(qs[3], qs[2], qs[1]);
            
            
            
            CNOT(qs[3], qs[0]);
            CNOT(qs[3], qs[1]);
            CNOT(qs[3], qs[2]);
            
            (Controlled H)([qs[0], qs[1], qs[2]], qs[3]);
            
            
            
            X(qs[3]);
            
            (Controlled H)([qs[3], qs[2], qs[1]], qs[0]);
            (Controlled H)([qs[3], qs[2], qs[0]], qs[1]);
            CCNOT(qs[3], qs[2], qs[1]);
            (Controlled H)([qs[3], qs[2], qs[1]], qs[0]);
            CCNOT(qs[3], qs[2], qs[1]);
            (Controlled X)([qs[3], qs[2], qs[1]], qs[0]);
            
            (Controlled X)([qs[3], qs[0], qs[2]], qs[1]);
            (Controlled H)([qs[3], qs[0], qs[1]], qs[2]);
            
            CNOT(qs[3], qs[2]);
            (Controlled H)([qs[3], qs[2], qs[1]], qs[0]);
            (Controlled H)([qs[3], qs[2], qs[0]], qs[1]);
            CNOT(qs[3], qs[1]);
            (Controlled H)([qs[3], qs[2], qs[1]], qs[0]);
            CNOT(qs[3], qs[1]);
            (Controlled X)([qs[3], qs[2], qs[1]], qs[0]);
            CNOT(qs[3], qs[2]);
            
            (Controlled X)([qs[3], qs[0], qs[2]], qs[1]);
            CCNOT(qs[3], qs[2], qs[1]);
            (Controlled X)([qs[3], qs[2], qs[1]], qs[0]);
            CCNOT(qs[3], qs[2], qs[1]);
            
            X(qs[3]);
            
            
            
            CNOT(qs[3], qs[0]);
            CNOT(qs[3], qs[1]);
            CNOT(qs[3], qs[2]);
        }
    }
}