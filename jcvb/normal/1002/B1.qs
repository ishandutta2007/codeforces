namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (qs : Qubit[]) : Int {
		mutable ret = 0;
		for (q in qs ){
			if (M(q)==One) {
				set ret = 1;
			}
		}
		return ret;
	}


}