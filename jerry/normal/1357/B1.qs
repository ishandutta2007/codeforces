namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Increment (number : Qubit[]) : Unit is Adj+Ctl {
        let n = Length(number);
        for (i in 1 .. n-1) {
            Controlled X(number[0..n-i-1], number[n-i]);
        }
        X(number[0]);
    }

    operation DoCount (inputs : Qubit[], outputs : Qubit[]) : Unit is Adj+Ctl {
        let n = Length(inputs);
        for (i in 0..n-1) {
            Controlled Increment([inputs[i]], outputs);
        }
    }

    operation XorMid (count : Qubit[], n : Int) : Unit is Adj+Ctl {
        if (n % 4 >= 2) {
            X(count[0]);
        }
        if (n % 8 >= 4) {
            X(count[1]);
        }
        if (n >= 8) {
            X(count[2]);
        }
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n = Length(inputs);
        using (count = Qubit[3]) {
            DoCount(inputs, count);
            XorMid(count, n);
            ApplyToEachCA(X, count);
            Controlled X(count, output);
            ApplyToEachCA(X, count);
            Adjoint XorMid(count, n);
            Adjoint DoCount(inputs, count);
        }
    }
}