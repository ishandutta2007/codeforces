namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
            let n = Length(register!);
            X(register![0]);
            for (i in 0..n-2) {
                Controlled X(register![0..i], register![i + 1]);
            }

    }
}