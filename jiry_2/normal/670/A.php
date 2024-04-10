<?php
$n=trim(fgets(STDIN));
$ans1=0;
$ans2=$n;
if ($n<=7) $ans2=max(0,$n-5);
for ($i=0;($i<7)&&($i<=$n);$i++){
	$a=(int)(($n-$i)/7);
	$b=($n-$i)%7;
	$c=$a*2+min($i,2)+max(0,$b-5);
	$ans1=max($ans1,$c);
	$ans2=min($ans2,$c);
}
echo "$ans2 $ans1";
?>