<?php
// Retrieve input
$stdin = fopen('php://stdin', 'r');
function input() 
{
    global $stdin;
    $ashar = explode(" ", trim(fgets($stdin)));
    return $ashar[0];
}

$N = input();
$N[0] = strtoupper($N[0]);
echo $N;
echo "\n";

?>