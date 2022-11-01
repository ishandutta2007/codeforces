namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation CheckPeriodWorks(x : Qubit[], y : Qubit, tmp : Qubit[], k : Int) : Unit {
        mutable n = Length(x);
        for (i in 0..n-k-1) {
            CNOT(x[i], tmp[i]);
            CNOT(x[i+k], tmp[i]);
            X(tmp[i]);
        }
        Controlled X(tmp[0..n-k-1], y);
        for (i in 0..n-k-1) {
            CNOT(x[i], tmp[i]);
            CNOT(x[i+k], tmp[i]);
            X(tmp[i]);
        }
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body {
            mutable n = Length(x);
            if (n >= 3) {
                using (periods = Qubit[n-1]) {
                    for (k in 2..n-1) {
                        CheckPeriodWorks(x, periods[k-2], periods[k-1..n-2], k);
                    }
                    ApplyToEach(X, periods[0..n-3]);
                    Controlled X(periods[0..n-3], y);
                    ApplyToEach(X, periods[0..n-3]);
                    for (k in 2..n-1) {
                        CheckPeriodWorks(x, periods[n-k-1], periods[n-k..n-2], n-k+1);
                    }
                }
            } else {
                CNOT(x[0], y);
                CNOT(x[1], y);
            }
            X(y);
        }
        adjoint self;
    }
}