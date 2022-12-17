program q;  {$Q- $R-}
var i,  d, n, j, k, v, l, r: longint; i1, j1: int64;
    m, b: array[0..1000000]of int64;
    c, a: array[0..1000000]of longint;
    s: array[0..1000000]of record l, r, s: longint; end;

procedure push(i: longint);
begin
    b[2*i + 1] := b[2*i + 1] + b[i];
    b[2*i + 2] := b[2*i + 2] + b[i];
    b[i] := 0;
end;

procedure ad(v, l, r, vl, vr: longint; x: int64);
begin
    if (l <= vl) and (r >= vr) then
        b[v] := b[v] + x
    else
        if (l >= vr) or (r <= vl) then
            v := v
        else
        begin
            ad(2*v + 1, l, r, vl, (vl + vr) div 2, x);
            ad(2*v + 2, l, r, (vl + vr) div 2, vr, x);
        end;
end;

function znach(v, l, vl, vr: longint): int64;
begin
    if (vl = l) and (vl = vr - 1) then
        znach := b[v]
    else
        if (vl > l) or (l >= vr) then
            znach := 1
        else
        begin
            push(v);
            znach := znach(2*v + 1, l, vl, (vl + vr) div 2)*znach(2*v + 2, l, (vl + vr) div 2, vr);
        end;
end;

procedure izm(v, l, vl, vr, o: longint);
var x, u: longint; b: byte;
begin
    if (vl = l) and (vr = l + 1) then
    begin
        a[l] := o;
        s[v].s := abs(o);
        s[v].r := abs(o);
        s[v].l := abs(o);
    end
    else
       if (vl > l) or (vr <= l) then l := l else
       begin
           u := (vl + vr) div 2;
           izm(2*v + 1, l, vl, u, o);
           if (vl + vr) div 2 > n - 1 then
           begin
               s[v] := s[2*v + 1];
           end
           else
           begin
           izm(2*v + 2, l, u, vr, o);
           if ((a[u - 1] >= 0) and (a[u] <> 0)) or
              ((a[u - 1] = -1) and (a[u] = -1)) then
           b := 1 else b := 0;
           if b = 1 then x := s[2*v + 1].r + s[2*v + 2].l else x := 0;
           if s[2*v + 1].s > x then x := s[2*v + 1].s;
           if s[2*v + 2].s > x then x := s[2*v + 2].s;
           s[v].s := x;
           if s[2*v + 2].r = (vr - vl) div 2 then
                if b = 1 then
                     s[v].r := s[v].s
                else
                     s[v].r := (vr - vl) div 2
           else
               s[v].r := s[2*v + 2].r;
           if (s[2*v + 1].l = (vr - vl) div 2) and (b = 1) then
               s[v].l := s[v].s
           else
               s[v].l := s[2*v + 1].l;
           end;
       end;
end;


begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    readln(n);
    v := 1;
    while v < n do v := v * 2;
    for i := 1 to n do
    begin
        read(c[i]);
        ad(0, i, i + 1, 1, v + 1, c[i]);
    end;
    {for i := 0 to 2 * v do
    begin
        s[i].s := 1;
        s[i].l := 1;
        s[i].r := 1;
    end;    }
    for i := 2 to n do
    if c[i] > c[i - 1] then
        izm(0, i - 1, 1, v + 1, 1)
    else
        if c[i] < c[i - 1] then
        izm(0, i - 1, 1, v + 1, -1);
    read(k);
    for i := 1 to k do
    begin
        read(l, r, j);
        ad(0, l, r + 1, 1, v + 1, j);
        if l <> 1 then
        begin
            i1 := znach(0, l - 1, 1, v + 1);
            j1 := znach(0, l, 1, v + 1);
            if j1 - i1 = 0 then izm(0, l - 1, 1, v + 1, 0);
            if j1 - i1 > 0 then izm(0, l - 1, 1, v + 1, 1);
            if j1 - i1 < 0 then izm(0, l - 1, 1, v + 1, -1);
        end;
        if r <> n then
        begin
        i1 := znach(0, r, 1, v + 1);
        j1 := znach(0, r + 1, 1, v + 1);
        if j1 - i1 = 0 then izm(0, r, 1, v + 1, 0);
        if j1 - i1 > 0 then izm(0, r, 1, v + 1, 1);
        if j1 - i1 < 0 then izm(0, r, 1, v + 1, -1);
        end;
        writeln(s[0].s + 1);
    end;
end.