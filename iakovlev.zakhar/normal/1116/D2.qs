namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation EvaluateEqualityClauses(x : Qubit[], d : Int, sz : Int) : Unit {
        body (...) {
            for (i in 0 .. d) {
                X(x[sz - 1 - d]);
            }
            for (i in 0 .. sz - 2 - d) {
                if (d == 0) {
                    (ControlledOnInt(0, H))([x[sz - 1]], x[i]);
                }
                if (d == 1) {
                    (ControlledOnInt(1, H))([x[sz - 2], x[sz - 1]], x[i]);
                }
                if (d == 2) {
                    (ControlledOnInt(0, H))([x[sz - 3], x[sz - 2], x[sz - 1]], x[i]);
                }
                if (d == 3) {
                    (ControlledOnInt(1, H))([x[sz - 4], x[sz - 3], x[sz - 2], x[sz - 1]], x[i]);
                }
            }
            for (i in 0 .. d) {
                X(x[sz - 1 - d]);
            }
        }
        adjoint auto;
    }

    operation Solve (qs : Qubit[]) : Unit {
        let sz = Length(qs);
        for (i in 0 .. sz - 2) {
            EvaluateEqualityClauses(qs, i, sz);
        }
    }
}