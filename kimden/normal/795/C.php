<?php
$n = (int) fgets(STDIN);
if($n % 2 == 1){
    echo "7";
    $n = $n - 3;
}
for($o = 0; $n >= 2; $n = $n - 2)
{
	echo "1";
}
?>