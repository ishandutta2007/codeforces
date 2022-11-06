namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    operation Solve(p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        let n = PowI(2, Length(inputRegister!));
        let x = p % n;
        if (x < n / 2) {
            for (i in 1 .. x) {
                QFTLE(inputRegister);
            }
        }
        else {
            for (i in x + 1 .. n) {
                Adjoint QFTLE(inputRegister);
            }
        }
    }
}