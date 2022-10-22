namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        using (x = Qubit[1]) {
            CNOT(qs[1], x[0]);
            CNOT(qs[2], x[0]);
            
            X(x[0]);
            CCNOT(x[0], qs[1], qs[2]);
            (Controlled H)([x[0]], qs[1]);
            CCNOT(x[0], qs[1], qs[2]);
            X(x[0]);
            
            CCNOT(x[0], qs[0], qs[1]);
            CCNOT(x[0], qs[0], qs[2]);
            
            (Controlled H)([x[0]], qs[0]);
            
            CCNOT(x[0], qs[0], qs[1]);
            CCNOT(x[0], qs[0], qs[2]);
            
            X(x[0]);
            (Controlled H)([x[0]], qs[0]);
            X(x[0]);
            
            X(qs[0]);
            CCNOT(qs[0], x[0], qs[1]);
            CCNOT(qs[0], x[0], qs[2]);
            X(qs[0]);
            
            CNOT(qs[1], x[0]);
            CNOT(qs[2], x[0]);
        }
    }
}