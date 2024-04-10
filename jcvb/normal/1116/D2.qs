namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;
 
 
	operation Solve (x: Qubit[]) : Unit is Adj+Ctl {
		let n = Length(x);
		if(n>1) {
			(ControlledOnInt(0,Solve))([x[n-1]],x[0..n-2]);
			for (j in 0..n-2) {
				Controlled H([x[n-1]],x[j]);
			}
		}
	}
 
 
}