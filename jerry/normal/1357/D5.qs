namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return (
            (1, [0.5, 1.0]),
            CombinedStructure([
                    LocalRotationsLayer(2, PauliX)
                ,   CyclicEntanglingLayer(2, PauliZ, 1)
                ,   LocalRotationsLayer(2, PauliZ)
                ,   CyclicEntanglingLayer(2, PauliX, 1)
                ,   LocalRotationsLayer(2, PauliX)
            ]),
            ([      -4.359458151569303
                ,   -5.944749874437553
                ,   -1.5182902887401697
                ,   -0.867700275212144
                ,   -3.662460026346547
                ,   -4.061822189302708
                ,   -2.2586317374548948
                ,   -0.22410811428279281
                ,   -6.3126444398091905
                ,   -4.383715418223543
             ], 0.16120665112249177)
        );
    }
}