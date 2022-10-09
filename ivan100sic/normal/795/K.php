<?php

$s = file_get_contents('php://stdin');

$s .= '.';

$n = strlen($s);

$serija = ',';
$duzina = 0;

$activated = 0;

function kons($x) {
	switch($x) {
		case 'a': return false;
		case 'e': return false;
		case 'i': return false;
		case 'o': return false;
		case 'u': return false;
		case 'y': return false;
	}
	return true;
}

for ($i = 0; $i < $n; $i++) {
	$novo = $s[$i];

	if ($novo == '.') {
		if ((($serija == 'e' || $serija == 'o') && $duzina == 2) || kons($serija)) {
			for ($j = 0; $j < $duzina; $j++) {
				echo $serija;
			}
		} else if ($duzina > 0) {
			echo $serija;
		}
		break;
	}

	if (!is_numeric($novo) && $activated == 0) {
		$activated = 1;
		continue;
	}

	if ($activated == 1) {
		if ($novo == $serija) {
			$duzina++;
		} else {
			if ((($serija == 'e' || $serija == 'o') && $duzina == 2) || kons($serija)) {
				for ($j = 0; $j < $duzina; $j++) {
					echo $serija;
				}
			} else if ($duzina > 0) {
				echo $serija;
			}
			$serija = $novo;
			$duzina = 1;
		}
	}	

}