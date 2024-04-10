program q;
const mx = 2000000000000000000;
var a, b: array[0..200000]of record i, j: int64; end;
    n, m, i, j: longint;
    x, s, max, k: int64;

function min(a, b: longint): longint;
begin
    if a > b then min := a else min := b;
end;

procedure sort(first, last: longint);
var f, l, mid: longint;
begin
    f := first;
    l := last;
    mid := a[(f + l) div 2].j;
    repeat
        while a[f].j < mid do inc(f);
        while a[l].j > mid do dec(l);
        if f <= l then
        begin
            a[0] := a[f];
            a[f] := a[l];
            a[l] := a[0];
            inc(f);
            dec(l);
        end;
    until f > l;
    if f < last then sort(f, last);
    if first < l then sort(first, l);
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    read(k, m, n);
    read(x, s);
    for i := 1 to m do
    read(a[i].i);
    for i := 1 to m do
    read(a[i].j);
    for i := 1 to n do
    read(b[i].i);
    for i := 1 to n do
    read(b[i].j);
    sort(1, m);
    j := n;
    max := x * k;
    a[0].i := x;
    a[0].j := 0;
    for i := 0 to m do
    begin
        while (j > 0) and (b[j].j + a[i].j > s) do dec(j);
        if b[j].j + a[i].j <= s then
        if max > (k - b[j].i) * a[i].i
        then max := (k - b[j].i) * a[i].i;
    end;
    write(max);
end.