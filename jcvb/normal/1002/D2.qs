namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (x : Qubit[], y : Qubit, b : Int[]) : Unit {
		let n = Length(x);
		for (i in 0..n-1) {
			if (b[i]==1) {
				CNOT(x[i],y);
			} else {
				X(x[i]);
				CNOT(x[i],y);
				X(x[i]);
			}
		}
	}


}