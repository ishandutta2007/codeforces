namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


     operation Solve (x : Qubit[], y : Qubit) : Unit {
		 for (q in x) {
			 CNOT(q,y);
		 }
	 }


}