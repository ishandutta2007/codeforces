program ps;  {$Q+ $R+}
const maxn = 300000;
      maxint = 2000000001;

var i, j, n, k, top, o: longint;  x, l, r, l1, l2, r1, r2:int64;
    a: array[0..maxn]of record l, r: int64; end;
    m: array[0..2*maxn]of record t, j: longint; end;

procedure sort(first, last: longint);
var f, l, mid: longint;
begin
    f := first;
    l := last;
    mid := m[(f + l) div 2].t;
    repeat
        while m[f].t < mid do inc(f);
        while m[l].t > mid do dec(l);
        if f <= l then
        begin
            m[0] := m[f];
            m[f] := m[l];
            m[l] := m[0];
            dec(l);
            inc(f);
        end;
    until f > l;
    if f < last then sort(f, last);
    if first < l then sort(first, l);
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    read(n, k);
    for i := 1 to n do
    read(a[i].l, a[i].r);
    l := 0;
    r := maxint + 1;
    l2 := -1;
    r2 := 0;
    while r - l > 1 do
    begin
        x := (r - l) div 2 + l;
        l1 := 1;
        r1 := 0;
        top := 0;
        for i := 1 to n do
        begin
            inc(top);
            m[top].t := a[i].l;
            m[top].j := 1;
            inc(top);
            if a[i].r - x + 2 < m[top - 1].t then
                m[top].t := m[top - 1].t
            else
                m[top].t := a[i].r - x + 2;
            m[top].j := -1;
        end;
        sort(1, top);
        i := 1;
        o := 0;
        while i <= top do
        begin
            o := o + m[i].j;
            inc(i);
            while (i <= top) and (m[i].t = m[i - 1].t) do
            begin
                o := o + m[i].j;
                inc(i);
            end;
            if o > r1 then begin l1 := m[i - 1].t; r1 := o; end;
        end;
        if r1 >= k then
        begin
            l := x;
            l2 := l1;
        end
        else
            r := x;
    end;
    writeln(l);
    o := 0;
    if l2 = -1 then
    begin
        for i := 1 to k do
        write(i, ' ');
        halt(0);
    end;
    for i := 1 to n do
    if (o < k) and (a[i].l <= l2) and (a[i].r >= l2 + l - 1) then
    begin
        inc(o);
        write(i, ' ');
    end;
end.