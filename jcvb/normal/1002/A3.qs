namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (qs : Qubit[], bits0 : Bool[],bits1: Bool[]) : Unit {
		let n = Length(bits0);
		mutable fi = -1;

		for (i in 0..n-1) {
			if (bits0[i] != bits1[i]) {
				set fi = i;
			}
		}
		if (fi != -1)  {
			H(qs[fi]);
			for (i in 0..n-1) {
				if ((i!=fi) and (bits0[i] != bits1[i])) {
					CNOT(qs[fi],qs[i]);
				}
			}
		}
		for (i in 0..n-1) {
			if (bits0[i]) {
				X(qs[i]);
			}
		}
	}


}