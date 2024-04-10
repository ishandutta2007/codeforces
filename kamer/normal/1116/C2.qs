namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;

    // length of y should be length of x - 1
    operation FillPeriods(x : Qubit[], y : Qubit[]) : Unit
        is Ctl + Adj {
        for (p in 1..Length(x)-1) {
            for (i in 0..Length(x) - 1 - p) {
                X(x[i + p]);
                CNOT(x[i + p], x[i]);
                X(x[i + p]);
            }
            Controlled X(x[0..Length(x) - 1 - p], y[p - 1]);
            for (i in Length(x) - 1 -p..-1..0) {
                X(x[i + p]);
                CNOT(x[i + p], x[i]);
                X(x[i + p]);
            }
        }  
    }

    operation C2 (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            // your code here
            using (q = Qubit[Length(x) - 1]) {
                FillPeriods(x, q);
                X(y);
                (ControlledOnBitString(IntAsBoolArray(0, Length(q)), X))(q, y);
                Adjoint FillPeriods(x, q);
            }
        }
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            // your code here
            C2(x, y);
        }
        adjoint auto;
    }
}