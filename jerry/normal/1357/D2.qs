namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Math;

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return (
            (4, [1.0, 0.75]),
            [       ControlledRotation((0, [1]), PauliX, 0)
                ,   ControlledRotation((1, [0]), PauliX, 0)
                ,   ControlledRotation((0, [1]), PauliX, 0)
            ],
            ([      PI()
             ], 0.0)
        );
    }
}