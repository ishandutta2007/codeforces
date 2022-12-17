program q;
var i, j, k, n, h: longint;
    a: array[1..200000]of record p, b: longint; t: boolean; end;


begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    read(n);
    for i := 1 to n do
    read(a[i].p);
    for i := 1 to n do
    read(a[i].b);
    k := 1;
    for i := 1 to n do
    if a[i].b = 1 then k := (k + 1) mod 2;
    h := 1;
    i := 1;
    while h <= n do
    begin
        a[i].t := true;
        if a[a[i].p].t = true then
        begin
            while (h <= n) and (a[h].t = true) do
            inc(h);
            if h > n then
            if a[i].p <> 1 then inc(k)
            else
            else begin inc(k); i := h; end;
        end else
        begin
            i := a[i].p;

        end;
    end;
    write(k);
end.