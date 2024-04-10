<?php
$f=STDIN;
$n=trim(fgets($f));
$a=explode(' ',trim(fgets($f)));
$m=trim(fgets($f));
$b=explode(' ',trim(fgets($f)));
$c=explode(' ',trim(fgets($f)));
$M=array();
for ($i=0;$i<$n;$i++)
	$M[$a[$i]]++;
$ans1=0;
$ans2=0;
$where=0;
for ($i=0;$i<$m;$i++)
	if ($M[$b[$i]]>$ans1||($M[$b[$i]]==$ans1&&$M[$c[$i]]>=$ans2)){
		$ans1=$M[$b[$i]]; $ans2=$M[$c[$i]]; $where=$i+1;
	}
echo $where;
?>