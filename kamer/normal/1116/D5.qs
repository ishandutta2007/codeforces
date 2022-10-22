namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Creeper (qs : Qubit[]) : Unit 
        is Adj {
        // your code here
        for (q in qs) {
            X(q);
        }
        H(qs[0]);
        for (i in 1..Length(qs)-1) {
            CNOT(qs[0], qs[i]);
        }
        (ControlledOnBitString([false, false], H))([qs[1], qs[2]], qs[0]);
        (ControlledOnBitString([true, true], H))([qs[1], qs[2]], qs[0]);
    }

    operation Solve(qs : Qubit[]) : Unit {
        Adjoint Creeper(qs);
    }

}