namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (qs : Qubit[], bits : Bool[]) : Unit {
		let n = Length(bits);
		mutable fi = -1;

		for (i in 0..n-1) {
			if (bits[i] == true ) {
				set fi = i;
			}
		}
		if (fi != -1)  {
			H(qs[fi]);
			for (i in 0..n-1) {
				if ((i!=fi) and (bits[i])) {
					CNOT(qs[fi],qs[i]);
				}
			}
		}
	}


}