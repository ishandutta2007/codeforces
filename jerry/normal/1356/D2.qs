namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Math;

    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        return ([ControlledRotation((0, new Int[0]), PauliY, 0)], ([1.0121970114513341], 0.25));
    }
}