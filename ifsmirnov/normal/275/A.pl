use warnings;
use strict;

my @size = 0..2;
sub ok {
    while (my $a = shift) {
        return 0 unless $a ~~ @size;
    }
    return 1;
}

my %h;

foreach my $i (@size) {
    foreach my $j (0..2) {
        $h{$i}{$j} = 0;
    }
}

foreach my $i (@size) {
    my $in = <STDIN>;
    my @params = split(/ /, $in);
    foreach my $j (@size) {
        foreach my $dx (-1..1) {
            foreach my $dy (-1..1) {
                $h{$i+$dx}{$j+$dy} += $params[$j] if !$dx || !$dy and ok($i+$dx, $j+$dy);
            }
        }
    }
}
foreach my $i (@size) {
    foreach my $j (@size) {
        print 1-$h{$i}{$j}%2;
    }
    print "\n";
}