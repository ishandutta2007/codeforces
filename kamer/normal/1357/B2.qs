    namespace Solution {
        open Microsoft.Quantum.Intrinsic;
        open Microsoft.Quantum.Canon;
     

     
        operation PlusOne(qs : Qubit[]) : Unit
        is Ctl + Adj {
            X(qs[0]);
            for (i in 0..Length(qs)-2) {
                ApplyToEachCA(X, qs[0..i]);
                Controlled X(qs[0..i], qs[i + 1]);
                ApplyToEachCA(X, qs[0..i]);
            }
        }
        
        operation MinusOne(qs : Qubit[]) : Unit
        is Ctl + Adj {
            X(qs[0]);
            for (i in 0..Length(qs)-2) {
                Controlled X(qs[0..i], qs[i + 1]);
            }
        }
        
        operation FillCounters(qs : Qubit[], counter : Qubit[]) : Unit
        is Ctl + Adj {
            for (i in 0..2..Length(qs)-1) {
                Controlled PlusOne([qs[i]], counter);
            }
            for (i in 1..2..Length(qs)-1) {
                Controlled MinusOne([qs[i]], counter);
            }
        }
        
        operation CheckEqual(counter : Qubit[], y : Qubit) : Unit
        is Ctl + Adj {
            for (q in counter) {
                X(q);
            }
            Controlled X(counter, y);
            for (q in counter) {
                X(q);
            }
            
            PlusOne(counter);
            PlusOne(counter);
            PlusOne(counter);
            for (q in counter) {
                X(q);
            }
            Controlled X(counter, y);
            for (q in counter) {
                X(q);
            }
            MinusOne(counter);
            MinusOne(counter);
            MinusOne(counter);
            
            MinusOne(counter);
            MinusOne(counter);
            MinusOne(counter);
            for (q in counter) {
                X(q);
            }
            Controlled X(counter, y);
            for (q in counter) {
                X(q);
            }
            PlusOne(counter);
            PlusOne(counter);
            PlusOne(counter);
            
        }
        
        operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
            // your code here
            using ((counter) = (Qubit[3])) {
                FillCounters(inputs, counter);
                CheckEqual(counter, output);
                Adjoint FillCounters(inputs, counter);
            }
        }

    }