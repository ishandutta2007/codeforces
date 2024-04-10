namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[]) : Unit {
        body (...) {
            let n = Length(x);
            ApplyToEachCA(CNOT(Tail(x), _), Most(x));
            IntegerIncrementLE(1, LittleEndian(Most(x)));
            ApplyToEachCA(X, Most(x));
            H(Tail(x));
            ApplyToEachCA(CNOT(Tail(x), _), Most(x));
        }
        adjoint auto;
    }

    operation SingleArgumentSolve(x: Qubit[]) : Unit {
        body (...) {
            // Solve(x[1 .. Length(x) - 1], Head(x));
            Solve(x);
        }
        adjoint auto;
    }
}