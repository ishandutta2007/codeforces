program q;  {$Q- $R-}
var i, n, j, p, k, x, t, s, l, r, o: longint;
    m: array[0..200001]of longint;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    read(n, k);
    for i := 1 to n do
    begin
        read(j);
        if (j = 0) and (i <> k) then begin inc(o); inc(p); end else
        if (i = k) and (J <> 0) then inc(o) else inc(m[j]);
    end;
    m[0] := 1;
    i := 1;
    j := n;
    while m[j] = 0 do dec(j);
    while i < j do
    begin
        if m[i] = 0 then
            if p > 0 then dec(p)
        else
        begin
            inc(o);
            dec(m[j]);
            while m[j] = 0 do dec(j);
        end;
        inc(i);
    end;
    write(o);
end.