<?php
list($n,$k)=explode(' ',trim(fgets(STDIN)));
$A=explode(' ',trim(fgets(STDIN)));
for ($i=1;$i<=$n;$i++){
	if ($k<=$i){
		echo $A[$k-1];
		return;
	} else $k-=$i;
}
?>