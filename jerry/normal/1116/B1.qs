namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation FirstType (qs : Qubit[]) : Unit {
        body {
            R(PauliY, 1.9106332362490184, qs[0]);
            CNOT(qs[0], qs[1]);
            Controlled H([qs[1]], qs[2]);
            CNOT(qs[2], qs[1]);
            
            X(qs[1]);
            Controlled Rz([qs[0], qs[1]], (-4.1887902047863905, qs[2]));
            X(qs[1]);
            X(qs[2]);
            Controlled Rz([qs[0], qs[2]], (4.1887902047863905, qs[1]));
            X(qs[2]);
            X(qs[0]);
        }
        adjoint auto;
    }

    operation Solve (qs : Qubit[]) : Int {
        Adjoint FirstType(qs);
        if (M(qs[0]) == Zero && M(qs[1]) == Zero && M(qs[2]) == Zero) {
            return 0;
        }
        return 1;
    }
}