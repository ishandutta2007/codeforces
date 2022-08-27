namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (x : Qubit[], y : Qubit) : Unit {
		Controlled X([x[0],x[1]],y);
		Controlled X([x[1],x[2]],y);
		Controlled X([x[0],x[2]],y);
	}


}