namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Increment (count : Qubit[]) : Unit is Adj+Ctl {
        Controlled X([count[0]], (count[1]));
        X(count[0]);
        using (q = Qubit()) {
            Controlled X(count, q);
            Controlled ApplyToEachCA([q], (X, count));
            ApplyToEachCA(X, count);
            Controlled X(count, q);
            ApplyToEachCA(X, count);
        }
    }

    operation DoCount (inputs : Qubit[], count : Qubit[]) : Unit is Adj+Ctl {
        let n = Length(inputs);
        for (i in 0..n-1) {
            if (i % 2 == 0) {
                Controlled Increment([inputs[i]], (count));
            } else {
                Controlled Adjoint Increment([inputs[i]], (count));
            }
        }
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using (count = Qubit[2]) {
            DoCount(inputs, count);
            ApplyToEachCA(X, count);
            Controlled X(count, output);
            ApplyToEachCA(X, count);
            Adjoint DoCount(inputs, count);
        }
    }
}