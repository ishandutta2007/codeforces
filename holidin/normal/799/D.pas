
{$R+ $Q+}
var m: array[0..100000]of longint; h, w, a, b, i, j, max, n, n1: longint;
    t: array[0..40]of int64;

procedure rec(h, w, i, mz: int64);
begin
    if (a <= h) and (b <= w) then
    begin
        if i + mz < max then max := i + mz;
    end else
    if i < n then
    begin
        if a > h then rec(h * m[i + 1], w, i + 1, mz);
        if b > w then rec(h, w * m[i + 1], i + 1, mz);
    end;
end;

procedure sort(first, last: longint);
var f, l, mid: longint;
begin
    f := first;
    l := last;
    mid := m[(f + l) div 2];
    repeat
         while m[f] > mid do inc(f);
         while m[l] < mid do dec(l);
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

begin
    {assign(input, 'input.txt'); reset(input);}
    read(a, b, h, w, n);
    for i := 1 to n do
    read(m[i]);
    sort(1, n);
    n1 := n;
    while (n > 0) and (m[n] = 2) do dec(n);
    n1 := n1 - n;
    max := 100;
    t[0] := 1;
    for i := 1 to 40 do
    t[i] := t[i - 1] * 2;
    if n1 > 40 then n1 := 40;
    for i := 0 to n1 do
    for j := 0 to n1 - i do
    begin
        rec(t[i] * h, t[j] * w, 0, i + j);
        rec(t[i] * w, t[j] * h, 0, i + j);
    end;
    if max = 100 then write(-1) else write(max);
end.