namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Helper(x: Qubit[], register: Qubit[]) : Unit {
        body (...) {
            for (b in x) {
                CCNOT(register[1], b, register[0]);
                CCNOT(register[0], b, register[1]);
                CNOT(b, register[0]);
            }
            ApplyToEachCA(X, register);
        }

        adjoint auto;
    }

    operation Solve(x : Qubit[], y: Qubit) : Unit {
        body (...) {
            using (tmp = Qubit[1]) {
                let register = [x[0], tmp[0]];
                Helper(Rest(x), register);
                Controlled X(register, y);
                Adjoint Helper(Rest(x), register);
            }
        }

        adjoint auto;
    }

}