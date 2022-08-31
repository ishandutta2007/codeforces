namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;


	operation Solve (x : Qubit[], y: Qubit) : Unit is Adj+Ctl{
		let n = Length(x);
		using ((q1,q2)=(Qubit(),Qubit())) {
			for (i in 0..2..n-1) {
				X(x[i]);
			}
			Controlled X(x,q1);
			for (i in 0..2..n-1) {
				X(x[i]);
			}

			for (i in 1..2..n-1) {
				X(x[i]);
			}
			Controlled X(x,q2);
			for (i in 1..2..n-1) {
				X(x[i]);
			}

			X(q1);
			X(q2);
			X(y);
			Controlled X([q1,q2],y);
			X(q1);
			X(q2);

			for (i in 1..2..n-1) {
				X(x[i]);
			}
			Controlled X(x,q2);
			for (i in 1..2..n-1) {
				X(x[i]);
			}

			for (i in 0..2..n-1) {
				X(x[i]);
			}
			Controlled X(x,q1);
			for (i in 0..2..n-1) {
				X(x[i]);
			}
		}

	}


}