namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        let reps = p % 4;
        for (i in 0..reps-1) {
            QFTLE(inputRegister);
        }
    }
}