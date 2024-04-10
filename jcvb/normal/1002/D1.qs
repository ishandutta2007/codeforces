namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (x : Qubit[], y : Qubit, b : Int[]) : Unit {
		let n = Length(x);
		for (i in 0..n-1) {
			if (b[i]==1 ) {
				Controlled X([x[i]], y);
			}
		}
	}


}