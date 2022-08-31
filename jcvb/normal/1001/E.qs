namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (qs : Qubit[]) : Int {
		CNOT(qs[0],qs[1]);
		H(qs[0]);
		mutable r0=0;
		mutable r1=0;
		if (M(qs[0]) == Zero) {
			set r0 = 0;
		} else {
			set r0 = 1;
		}
		if (M(qs[1]) == Zero) {
			set r1 = 0;
		} else {
			set r1 = 1;
		}

		return r1*2 + r0;
    }


}