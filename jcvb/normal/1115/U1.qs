namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;


	operation Solve (qs : Qubit[], bits: Bool[][]) : Unit {
		let n = Length(qs);
		using (r = Qubit[2]) {
			H(r[0]);
			H(r[1]);
			
			for (j in 0..3) {
				let j0 = j &&& 1;
				let j1 = (j>>>1) &&& 1;

				if (j0 == 0) {
					X(r[0]);
				}
				if (j1 == 0) {
					X(r[1]);
				}
				for (i in 0..n-1) {
					if (bits[j][i] == true) {
						Controlled X(r, qs[i]);
					}
				}

				if (j0 == 0) {
					X(r[0]);
				}
				if (j1 == 0) {
					X(r[1]);
				}
			}

			for (j in 0..3) {
				let j0 = j &&& 1;
				let j1 = (j>>>1) &&& 1;
				using (qq = Qubit() ) {
					for (i in 0..n-1) {
						if (bits[j][i]==false) {
							X(qs[i]);
						}
					}
					Controlled X(qs, qq);
					if (j0 == 1) {
						Controlled X([qq],r[0]);
					}
					if (j1 == 1) {
						Controlled X([qq],r[1]);
					}
					Controlled X(qs, qq);
					for (i in 0..n-1) {
						if (bits[j][i]==false) {
							X(qs[i]);
						}
					}
				}
			}
		}

	    }


}