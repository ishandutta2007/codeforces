namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (q : Qubit) : Int {
		H(q);
		if (M(q) == One) {
			return -1;
		} else {
			return 1;
		}
    }


}