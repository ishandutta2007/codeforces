namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation IsDifferent(l: Qubit[], r: Qubit[], y: Qubit) : Unit {
        body (...) {
            let n = Length(l);
            if (n != Length(r)) {
                fail "Expected equal lengths";
            }
            for (i in 0 .. n - 1) {
                CNOT(r[i], l[i]);
                X(l[i]);
            }
            Controlled X(l, y);
            for (i in 0 .. n - 1) {
                CNOT(r[i], l[i]);
                X(l[i]);
            }
            X(y);
        }

        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            using (anc = Qubit[n/2]) {
                for (i in 1..n/2) {
                    IsDifferent(x[0..i-1], x[n-i..n-1], anc[i-1]);
                }
                Controlled X(anc, y);
                X(y);
                for (i in 1..n/2) {
                    IsDifferent(x[0..i-1], x[n-i..n-1], anc[i-1]);
                }
            }
        }
        adjoint auto;
    }

    operation SingleArgumentSolve(x: Qubit[]) : Unit {
        body (...) {
            Solve(Rest(x), Head(x));
        }
    }
}