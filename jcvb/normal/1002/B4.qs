namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (qs: Qubit[]) : Int {
		H(qs[0]);
		CNOT(qs[0],qs[1]);
		mutable res = 0;
		if (M(qs[1])==Zero){
			set res += 1;
		}
		H(qs[0]);
		if (M(qs[0])== Zero) {
			set res += 2;
		}
		return res;
	}


}