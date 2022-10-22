// This file is submitted by the participant
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Math;

    // The operation that the participant has to implement
    // Has to return three things: 
    //  1) the feature engineering to perform (as an index in the array of feature engineering functions and an array of parameters to be used with it)
    //  2) circuit structure (as an array of ControlledRotation)
    //  3) and training results (circuit parameters + bias)
    //
    // The features engineering is built-in and cannot be tweaked by the participant's solution, only chosen from the list 
    // (see quantum-checker.qs for the list of available feature engineering functions)
    //
    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((4, [1.0, 0.0, 1.0, 0.0]), 
                [ControlledRotation((1, [3]), PauliX, 0),
                ControlledRotation((1, new Int[0]), PauliX, 1),
                ControlledRotation((0, [3]), PauliX, 2),
                ControlledRotation((3, [0]), PauliX, 3),
                ControlledRotation((3, [1]), PauliX, 4),
                ControlledRotation((3, [2]), PauliX, 5),
                ControlledRotation((3, new Int[0]), PauliX, 6)],
                ([PI(), PI(), PI(), PI() / 2.0, 1.6709637, PI(), PI()], 0.0));
    }


}