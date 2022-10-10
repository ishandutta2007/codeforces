<?php
//Codeforces Round #173 (Div. 2)
//13 Mar 2013

// Retrieve input
$stdin = fopen('php://stdin', 'r');
function input() 
{
	global $stdin;
	$ashar = explode(" ", trim(fgets($stdin)));
	return $ashar[0];
}

$N = input();
$risan = 0;

while ($N-- > 0)
{
	$s = input();
	if ($s == "++X" || $s == "X++") ++$risan;
	else --$risan;
}

echo $risan;
echo "\n";

?>