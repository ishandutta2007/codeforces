namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Next(b : Qubit[]) : Unit {
        body(...) {
            X(b[Length(b) - 1]);
            if (Length(b) > 1) {
                (ControlledOnBitString([false], Next))([b[Length(b) - 1]], b[0..Length(b) - 2]);
            }
        }
        controlled auto;
        adjoint auto;
    }

    operation Prev(b : Qubit[]) : Unit {
        body(...) {
            X(b[Length(b) - 1]);
            if (Length(b) > 1) {
                Controlled Prev([b[Length(b) - 1]], b[0..Length(b)-2]);
            }
        }
        controlled auto;
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            using (b = Qubit[4]) {
                for (i in 0..Length(x) - 1) {
                    Controlled Next([x[i]], b);
                }

                (ControlledOnBitString([false, false, false, false], X))(b, y);
                (ControlledOnBitString([false, false, true, true], X))(b, y);
                (ControlledOnBitString([false, true, true, false], X))(b, y);
                (ControlledOnBitString([true, false, false, true], X))(b, y);

                for (i in 0..Length(x) - 1) {
                    Controlled Prev([x[i]], b);
                }
            }
        }
        adjoint auto;
    }
}