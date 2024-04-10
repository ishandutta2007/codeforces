namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (qs : Qubit[]) : Unit {
		H(qs[0]);
		let n = Length(qs);
		for (j in 1..n-1) {
			CNOT(qs[0],qs[j]);
		}
    }


}