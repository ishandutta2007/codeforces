use warnings;
use strict;
my $n = int <>;
my $s = <>;
my @s = split //, $s;
my $cur = '-';
my $cnt = 0;
for my $i (0..$n) {
    if ($s[$i] eq $cur) {
        $cnt += 1;
    } else {
        unless ($cur eq '-') {
            if ($cnt == 2 and ($cur eq 'e' or $cur eq 'o')) {
                print $cur;
                print $cur;
            } elsif ($cur eq 'e' or $cur eq 'o' or $cur eq 'i' or $cur eq 'a' or $cur eq 'y' or $cur eq 'u') {
                print $cur;
            } else {
                for (0..$cnt-1) {
                    print $cur;
                }
            }
        }
        $cnt = 1;
        $cur = $s[$i];
    }
}
print "\n";