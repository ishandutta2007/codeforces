var m, d: array[0..1000000]of record i, j, k, ke: longint; end;
i, j, k, n, p, a, b, top: longint;
procedure bfs(i, oi, l, l1: longint);
var r, j: longint;
begin
    m[i].k := l;
    r := 1;
    j := m[i].i;
    while j <> 0 do
    begin
        if r = l then inc(r);
        if r = l1 then inc(r);
        if r = l then inc(r);
        if d[j].i <> oi then begin
             bfs(d[j].i, i, r, l); inc(r); end;
        j := d[j].j;
    end;
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);  }
    read(n);
    p := 0;
    for i := 1 to n do
    begin
        read(a, b);
        inc(m[a].ke);
        if m[a].ke + 1 > p then p := m[a].ke + 1;
        inc(m[b].ke);
        if m[b].ke + 1 > p then p := m[b].ke + 1;
        inc(top);
        d[top].i := b;
        if m[a].i = 0 then
            m[a].i := top
        else
            d[m[a].j].j := top;
        m[a].j := top;
        j := a;
        a := b;
        b := j;
        inc(top);
        d[top].i := b;
        if m[a].i = 0 then
            m[a].i := top
        else
            d[m[a].j].j := top;
        m[a].j := top;
    end;
    writeln(p);
    bfs(1, 0, 1, 0);
    for i := 1 to n do
    write(m[i].k, ' ');
end.