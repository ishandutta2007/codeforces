use warnings;
use strict;

<>;
my @a = map int, split /\s+/, <>;

my $res = 0;
for my $i (0..$#a) {
    for my $j ($i..$#a) {
        my $s = 0;
        map {$s += ( ($_ >= $i && $_ <= $j) ? 1 - $a[$_] : $a[$_]) } 0..$#a;
        $res = $s if $res < $s;
    }
}

print "$res\n";