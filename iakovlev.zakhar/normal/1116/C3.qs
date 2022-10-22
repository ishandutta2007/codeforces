namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            using (calc = Qubit[2]) {
                for (i in 0..Length(x)-1) {
                    CNOT(x[i], calc[0]);
                }
                for (i in 0..Length(x)-1) {
                    for (j in i+1..Length(x)-1) {
                        for (k in j+1..Length(x)-1) {
                            for (l in k+1..Length(x)-1) {
                                (Controlled X)([x[i], x[j], x[k], x[l]], calc[1]);
                            }
                        }
                    }
                }
                (ControlledOnInt(0, X))(x, y);
                if (n == 9) {
                    (Controlled X)(x, y);
                }
                X(calc[1]);
                for (i in 0..Length(x)-1) {
                    for (j in i+1..Length(x)-1) {
                        (Controlled X)([calc[0], calc[1], x[i], x[j]], y);
                    }
                }
                X(calc[1]);
                X(calc[0]);
                for (i in 0..Length(x)-1) {
                    for (j in i+1..Length(x)-1) {
                        (Controlled X)([calc[0], calc[1], x[i], x[j]], y);
                    }
                }
                X(calc[0]);
                for (i in 0..Length(x)-1) {
                    for (j in i+1..Length(x)-1) {
                        for (k in j+1..Length(x)-1) {
                            for (l in k+1..Length(x)-1) {
                                (Controlled X)([x[i], x[j], x[k], x[l]], calc[1]);
                            }
                        }
                    }
                }
                for (i in 0..Length(x)-1) {
                    CNOT(x[i], calc[0]);
                }
            }
        }
        adjoint auto;
    }
}