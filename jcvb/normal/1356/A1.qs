namespace Solution {
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
	    mutable number = 0;
	    using (q = Qubit()) { 
	    	    unitary(q); 
				if (M(q) == Zero) {
					set number = 0; 
				}
				else {
					set number = 1; Reset(q); 
				}
	    } 
	    return number;
    }
}