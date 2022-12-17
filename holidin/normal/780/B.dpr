program q;
var i, j, k, n, p: longint;
    var m: array[0..600000]of record i, j: extended end;
    x, x1, x2, x3, l, r: extended;

procedure sort(first, last: longint);
var f, l: longint; mid: extended;
begin
    f := first;
    l := last;
    mid := m[f + random(l - f + 1)].i;
    repeat
        while m[f].i < mid do inc(f);
        while m[l].i > mid do dec(l);
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

function max(a, b: extended): extended;
begin
    if a > b then max := a else max := b;
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);  }
    read(n);
    for i := 1 to n do
    read(m[i].i);
    for i := 1 to n do
    read(m[i].j);
    sort(1, n);
    l := 1;
    r := 1000000001;
    while r - l >= 0.000001 do
    begin
        x := (l + r) / 2;
        x1 := 0;
        for i := 1 to n do
        x1 := max(x1, abs(m[i].i - x)/m[i].j);
        x2 := 0;
        x3 := x - 0.000001;
        for i := 1 to n do
        x2 := max(x2, abs(m[i].i - x3)/m[i].j);
        if x1 >= x2 then
            r := x
        else
            l := x;
    end;
    x1 := 0;
    for i := 1 to n do
    x1 := max(x1, abs(m[i].i - l)/m[i].j);
    write(x1:7:7);
end.