<?php
$n = trim(fgets(STDIN));
$s = trim(fgets(STDIN));
if ($n>26) {echo -1;}
else {
	$b=array(); $ans=$n;
	for ($i=0;$i<$n;$i+=1) if ($b[$s[$i]]==0){
		$ans-=1; $b[$s[$i]]=1;
	}
	echo $ans;
}
?>