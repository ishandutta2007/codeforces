<?php
$a = trim(fgets(STDIN));
for ($i=1;$i<=$a;$i+=1) $b.=(string)$i;
echo $b[$a-1]; 
?>