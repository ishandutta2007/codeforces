use warnings;
use strict;

my @a = split //, <>;
my @s;
for (0..@a-2) {
  $s[$_] = 0;
  $s[$_] += 1 if $a[$_] eq $a[$_+1];
  $s[$_] += $s[$_-1] if $_;
}
push @s, 0;

for (1..int <>) {
  my ($l, $r) = map {int $_-1} split (/\s/, <>);
  print $s[$r-1] - $s[$l-1], "\n";
}