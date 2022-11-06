namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    operation Recursive(inputs : Qubit[], output : Qubit, num : Int, idx : Int) : Unit is Adj+Ctl {
        if (idx < 0) {
            if (num == 0) {
                Controlled X(inputs, output);
            }
        }
        else {
            let nxt = num * 2 % 3;
            X(inputs[idx]);
            Recursive(inputs, output, nxt, idx - 1);
            X(inputs[idx]);
            Recursive(inputs, output, (nxt + 1) % 3, idx - 1);
        }
    }
    operation Solve(inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        Recursive(inputs, output, 0, Length(inputs) - 1);
    }
}