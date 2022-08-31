namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;
 
   operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                // Prepare k-th basis vector
                let binary = IntAsBoolArray(k, N);
                
                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                
                // Apply the operation
                unitary(qs);
                
                // Dump the contents of the k-th column
                DumpMachine();
                
                ResetAll(qs);
            }
        }
    }
 
	operation Zuo(x:Qubit[]) :Unit is Adj+Ctl {
		Ry(2.0*ArcSin(Sqrt(1.0/3.0)),x[0]);
		(ControlledOnInt(0,H))([x[0]],x[1]);
		(ControlledOnInt(0,X))(x[0..1],x[2]);
		R1(2.0*PI()/3.0,x[1]);
		R1(4.0*PI()/3.0,x[2]);
	}

operation Solve (qs : Qubit[],parity : Int) : Unit {
	let n = Length(qs);
	mutable test  =0;
		using (r = Qubit() ){
			repeat {
			    Reset(r);
				ResetAll(qs);
				for (q in qs) {
					H(q);
				}
				for (q in qs) {
					CNOT(q,r);
				}
				if (parity == 0) {
					if (M(r)==Zero) {
						set test = 1;
					}else {
						set test = 0;
					}
				}else {
					if (M(r)==Zero) {
						set test = 0;
					}else {
						set test = 1;
					}
				}
			} until (test == 1 );
			Reset(r);
		}
        // your code here
    }

 
 
}