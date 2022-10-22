namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    operation EvaluateEqualityClauses (x : Qubit[], ancillaRegister : Qubit[]) : Unit {
        body (...) {
            let N = Length(x);
            for (i in 0 .. N - 2) {
                // Compute XOR of x[i] and x[N - 1 - i] into anc[i]
                CNOT(x[i], ancillaRegister[i]);
                CNOT(x[i + 1], ancillaRegister[i]);
                // Negate it (XOR has to equal 0 for equality to be 1)
                //X(ancillaRegister[i]);
            }
        }
        adjoint auto;
    }
    
    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let N = Length(x);
            using (anc = Qubit[N - 1]) {
                WithA(EvaluateEqualityClauses(x, _), Controlled X(_, y), anc);
            }
        }
        adjoint auto;
    }
}