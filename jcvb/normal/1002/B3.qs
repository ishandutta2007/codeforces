namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (qs : Qubit[]) : Int {
		H(qs[0]);
		H(qs[1]);
		mutable ret = 0;
		if (M(qs[0])==One) {
			set ret +=2;
		}
		if (M(qs[1]) == One) {
			set ret += 1;
		}
		return ret;
	}


}