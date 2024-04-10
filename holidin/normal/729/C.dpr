program q;  {$Q- $R-}
var i, n, j, p, k, x, t, s, l, r: longint;
    m: array[0..200001]of record i, j: int64; end;
    a: array[0..200001]of int64;

procedure sort(first, last: longint);
var f, l, mid, mid1: longint;
begin
    f := first;
    l := last;
    mid := m[(f + l) div 2].j;
    mid1 := m[(f + l) div 2].i;
    repeat
        while (m[f].j > mid) or ((m[f].j = mid) and (m[f].i < mid1)) do inc(f);
        while (m[l].j < mid) or ((m[l].j = mid) and (m[l].i > mid1)) do dec(l);
        if f <= l then
        begin
            m[0] := m[f];
            m[f] := m[l];
            m[l] := m[0];
            inc(f);
            dec(l);
        end;
    until f > l;
    if f < last then sort(f, last);
    if first < l then sort(first, l);
end;

procedure sort1(first, last: longint);
var f, l, mid: longint;
begin
    f := first;
    l := last;
    mid := a[(f + l) div 2];
    repeat
        while a[f] < mid do inc(f);
        while a[l] > mid do dec(l);
        if f <= l then
        begin
            a[0] := a[f];
            a[f] := a[l];
            a[l] := a[0];
            inc(f);
            dec(l);
        end;
    until f > l;
    if f < last then sort1(f, last);
    if first < l then sort1(first, l);
end;

function f(x: int64): boolean;
var i: longint; j: int64;  o: boolean;
begin
    a[0] := 0;
    a[k + 1] := s;
    j := 0;
    o := true;
    for i := 1 to k + 1 do
    if a[i] - a[i - 1] > x then o := false
       else
        if x >= 2*(a[i] - a[i - 1]) then
             j := j + a[i] - a[i - 1]
        else
             j := j + 3*(a[i] - a[i - 1]) - x;
    if j > t then o := false;
    f := o;
end;

begin
   { assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    readln(n, k, s, t);
    for i := 1 to n do
    read(m[i].i, m[i].j);
    for i := 1 to k do
    read(a[i]);
    l := 1;
    r := n + 1;
    sort(1, n);
    sort1(1, k);
    for i := 2 to n do
    begin
        if m[i].i > m[i - 1].i then m[i].i := m[i - 1].i;
    end;
    while l < r - 1 do
    begin
        x := (l + r) div 2;
        if f(m[x].j) then
            l := x
        else
            r := x;
    end;
    if f(m[l].j) then write(m[l].i) else write(-1);
end.