
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    operation EvaluateEqualityClauses (x : Qubit[], ancillaRegister : Qubit[], y : Int) : Unit {
        body (...) {
            let N = Length(x);
            for (i in 0 .. N - 1 - y) {
                // Compute XOR of x[i] and x[N - 1 - i] into anc[i]
                CNOT(x[i], ancillaRegister[i]);
                CNOT(x[i + y], ancillaRegister[i]);
                // Negate it (XOR has to equal 0 for equality to be 1)
                X(ancillaRegister[i]);
            }
        }
        adjoint auto;
    }
    
    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let N = Length(x);
            using (th = Qubit[N - (N + 1) / 2]) {
                for (i in (N + 1) / 2 .. N - 1) {
                    using (anc = Qubit[N - i]) {
                        WithA(EvaluateEqualityClauses(x, _, i), Controlled X(_, th[i - (N + 1) / 2]), anc);
                    }
                }
                for (i in 0 .. Length(th) - 1) {
                    X(th[i]);
                }
                Controlled X(th, y);
                X(y);
                for (i in 0 .. Length(th) - 1) {
                    X(th[i]);
                }
                for (i in (N + 1) / 2 .. N - 1) {
                    using (anc = Qubit[N - i]) {
                        WithA(EvaluateEqualityClauses(x, _, i), Controlled X(_, th[i - (N + 1) / 2]), anc);
                    }
                }
            }
        }
        adjoint auto;
    }
}