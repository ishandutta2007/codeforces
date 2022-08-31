namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;


	operation Jia (x: Qubit[]) : Unit is Adj+Ctl {
		CNOT(x[0],x[1]);
		X(x[0]);
		using (qq=Qubit() ) {
			Controlled X(x,qq);
			CNOT(qq,x[0]);
			CNOT(qq,x[1]);
			(ControlledOnInt(0,X))(x,qq);
		}
	}

	operation Solve (x : Qubit[], y: Qubit) : Unit is Adj+Ctl{
		let n = Length(x);

		using (qq = Qubit[2]) {
			for (q in x) {
				Controlled Jia([q], qq);
			}
			(ControlledOnInt(0,X))(qq,y);
			for (q in x) {
				Adjoint Controlled Jia([q], qq);
			}
		}
	}

}