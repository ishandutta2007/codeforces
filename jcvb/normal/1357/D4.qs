// This file is submitted by the participant
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;

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
        return ((1, [0.25,0.0]), 
                [
		ControlledRotation((0, [1]), PauliX, 0),
		ControlledRotation((1, [0]), PauliX, 0),
		ControlledRotation((0, [1]), PauliX, 0),
		ControlledRotation((1, new Int[0]), PauliX, 1),
    ],
     ([3.1415926535897,0.0],-0.02));
    //([1.867,2.333,7.886849999999998,1.7215070000000017,3.5161600000000006,3.0148200000000003,7.0785100000000005,2.93771], 0.08751863947681988));
     //([1.867,2.333,7.886849999999998,1.7215070000000017,3.5161600000000006,3.0148200000000003,7.0785100000000005,2.93771], 0.09684319822399473));
    //([1.867,2.333,7.886849999999998,1.7215070000000017,3.5161600000000006,3.0148200000000003,7.0785100000000005,2.93771], 0.09738319822399472));
     //([1.867,2.333,7.886849999999997,1.721507000000001,3.47892,2.9775799999999997,7.04127,2.93771], 0.09086897697254648));
     	//([1.567,2.333,7.998999999999999,1.8600570000000003,3.4257200000000005,2.89183,6.935270000000001,2.93771],0.10019808596944002));
    }


}