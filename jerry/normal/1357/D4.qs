namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return (
            (1, [0.3]),
            [       ControlledRotation((0, new Int[0]), PauliX, 0)
            ],
            ([      0.0
             ], 0.0)
        );
    }
}