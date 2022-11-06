namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    operation Recursive(inputs : Qubit[], output : Qubit, cnt : Int, idx : Int, n : Int) : Unit is Adj+Ctl {
        if (cnt < n / 2) {}
        elif (cnt == n / 2) {
            Controlled X(inputs, output);
        }
        elif (idx < n) {
            X(inputs[idx]);
            Recursive(inputs, output, cnt - 1, idx + 1, n);
            X(inputs[idx]);
            Recursive(inputs, output, cnt, idx + 1, n);
        }
    }
    operation Solve(inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        Recursive(inputs, output, Length(inputs), 0, Length(inputs));
    }
}