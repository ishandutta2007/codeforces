namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;


	operation Cha (x: Qubit[], res: Qubit[]) : Unit is Adj+Ctl {
		let n = Length(x);
		mutable ok = new Bool[n];
		for (l in 1..n-1) {
			if ((n-l)*2>=n) {
				for (j in 0..l-1) {
					CNOT(x[n-l+j],x[j]);
				}
				(ControlledOnInt(0,X))(x[0..l-1],res[l]);
				for (j in l-1..-1..0) {
					CNOT(x[n-l+j],x[j]);
				}
			}
		}
	}

	operation Solve (x : Qubit[], y: Qubit) : Unit is Adj+Ctl{
		let n = Length(x);
		using (res = Qubit[n]) {

			Cha(x,res);

			(ControlledOnInt(0,X))(res,y);
			X(y);

			Adjoint Cha(x,res);

		}

	}

}