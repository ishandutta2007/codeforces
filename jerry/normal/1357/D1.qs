namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return (
            (4, [0.5, 1.0]),
            new ControlledRotation[0],
            (new Double[0], 0.0)
        );
    }
}