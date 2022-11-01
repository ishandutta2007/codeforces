use warnings;
use strict;

sub max {
  if (not defined $_[1]) { return $_[0]; }
  return $_[0] > $_[1] ? $_[0] : $_[1];
}

my $s = <>;
my $x = int $s;

$x = max($x, int $s =~ s/.(.)$/$1/r);
$x = max($x, int $s =~ s/(.).$/$1/r);

print $x;