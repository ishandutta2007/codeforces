namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (q: Qubit) : Int {
		Ry(PI()/4.0,q);
		if (M(q)==Zero) {
			return 0;
		} else{
			return 1;
		}
	}

}