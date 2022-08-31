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

	operation cha (q: Qubit): Unit is Adj+Ctl {
		Rz(PI()*0.1,q);
	}
 

  operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
	  	let q = p%4;

		  for (j in 0..q-1) {
			  QFTLE(inputRegister);
		  }

        // your code here
    }

 
 
}