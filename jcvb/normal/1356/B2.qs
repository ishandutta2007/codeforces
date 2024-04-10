namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Arithmetic;


	operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        // your code here
		let n = Length(register!);
		for (i in 0..n-1) {
			X(register![i]);
		}
		for (i in n-1..-1..0) {
			Controlled X(register![0..i-1],register![i]);
		}
		for (i in 0..n-1) {
			X(register![i]);
		}
    }


}