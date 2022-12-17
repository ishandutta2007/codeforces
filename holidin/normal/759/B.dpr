program q;
var i, j, k, n, h, min, h1: longint;
    a: array[0..200000]of longint;
    b: array[0..200000]of longint;


begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    read(n);
    for i := 1 to n do
    read(a[i]);
    h := 1;
    h1 := 1;
    b[0] := 0;
    for i := 1 to n do
    begin
        while (h < i) and (a[h] + 90 <= a[i]) do inc(h);
        while (h1 < i) and (a[h1] + 1440 <= a[i]) do inc(h1);
        min := b[i - 1] + 20;
        if b[h - 1] + 50 < min then min := b[h - 1] + 50;
        if b[h1 - 1] + 120 < min then min := b[h1 - 1] + 120;
        b[i] := min;
        writeln(min - b[i - 1]);
    end;
end.