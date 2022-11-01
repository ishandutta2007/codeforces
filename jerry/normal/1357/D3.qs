namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Math;

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return (
            (1, [0.8, 0.0]),
            [       ControlledRotation((0, new Int[0]), PauliX, 0)
            ],
            ([      PI()
             ], 0.0)
        );
    }
}