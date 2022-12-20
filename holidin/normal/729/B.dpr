program q;  {$Q+ $R+}
var i, n, j, p, k: longint; c: char;  s: string;
    m, a, b: array[0..1001, 0..1001]of longint;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    readln(n, k);
    for i := 1 to n do
    for j := 1 to k do
    begin
        read(m[i, j]);
        a[i, j] := a[i, j - 1] + m[i, j];
        b[i, j] := b[i - 1, j] + m[i, j];
    end;
    p := 0;
    for i := 1 to n do
    for j := 1 to k do
    if m[i, j] = 0 then
    begin
        if (a[i, j] > 0) then inc(p);
        if a[i, k] - a[i, j] > 0 then inc(p);
        if b[i, j] > 0 then inc(p);
        if b[n, j] - b[i, j] > 0 then inc(p);
    end;
    write(p);
end.