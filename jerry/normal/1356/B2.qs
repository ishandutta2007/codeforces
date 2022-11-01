namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Increment (register : LittleEndian) : Unit is Adj+Ctl {
        let n = Length(register!);
        for (i in 1 .. n-1) {
            Controlled X(register![0..n-i-1], register![n-i]);
        }
        X(register![0]);
    }

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        Adjoint Increment(register);
    }
}