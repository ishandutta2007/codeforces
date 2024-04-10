program q;
var i, t, k, d, x, y, n: longint;
begin
    {assign(input, 'input.txt'); reset(input);}
    read(n, t, k, d);
    x := (d div t) * k;
    if d mod t = 0 then 
    if n - x <= k then
        writeln('NO')
    else
        Writeln('YES')
    else
    if n - (x + k) <= 0 then
    writeln('NO')
    else
    writeln('YES');
end.