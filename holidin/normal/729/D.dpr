program q;  {$Q- $R-}
var i, n, j, p, k, x, t, s, l, r, o, a, b: longint;   c: char;
    m: array[0..200001]of longint;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    readln(n, a, b, k);
    for i := 1 to n do
    begin
        read(c);
        if c = '1' then m[i] := 1;
    end;
    m[0] := 1;
    m[n + 1] := 1;
    i := 0;
    j := 1;
    p := 0;
    while m[j] = 0 do inc(j);
    while i < n do
    begin
        while j - i > b do
        begin
            inc(p);
            i := i + b;
        end;
        i := j;
        inc(j);
        while (i < n) and (m[j] = 0) do inc(J);
    end;
    if p > a  then o := p - a + 1 else o := 1;
    writeln(o);
    i := 0;
    j := 1;
    p := 0;
    while m[j] = 0 do inc(j);
    while (i < n) and (o > 0) do
    begin
        while (o > 0) and (j - i > b) do
        begin
            inc(p);
            dec(o);
            write(i + b, ' ');
            i := i + b;
        end;
        i := j;
        inc(j);
        while (i < n) and (m[j] = 0) do inc(J);
    end;
end.