namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        // your code here
        let cr = [
            ControlledRotation((0, new Int[0]), PauliY, 0)
        ];
        return (cr, ([3.1243749999999815], 0.0023500000000000187));
    }
}