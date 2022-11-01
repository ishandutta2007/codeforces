namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (x : Qubit[]) : Int {
        SingleArgumentSolve(x);
        ApplyToEach(X, x);
        mutable result = 0;
        using (q = Qubit()) {
            Controlled X(x, q);
            set result = ((M(q) == Zero) ? 1 | 0);
            Reset(q);
        }
        return result;
    }

    operation SingleArgumentSolve(x: Qubit[]) : Unit {
        body (...) {
            mutable coeff = new ComplexPolar[8];
            set coeff[4] = ComplexPolar(1.0, 0.0);
            set coeff[2] = ComplexPolar(1.0, PI() * 2.0 / 3.0);
            set coeff[1] = ComplexPolar(1.0, PI() * 4.0 / 3.0);
            Adjoint PrepareArbitraryState(coeff, BigEndian(x));
        }
    }
}