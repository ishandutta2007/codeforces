program q;
type mas = array[0..200000]of record i, j: longint end;

var i, t, k, d, x, y, n, j: longint;
    m: array[1..3]of mas;
    b: array[1..3, 0..200000]of boolean;
    a: array[0..200000]of record  c, c1, c2, b1, b2: longint; end;
    h, top: array[1..3]of longint;

procedure sort(first, last: longint; var m: mas);
var f, l, mid: longint;
begin
    f := first;
    l := last;
    mid := m[(f + l) div 2].i;
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
    if f < last then sort(f, last, m);
    if first < l then sort(first, l, m);
end;

begin
   { assign(input, 'input.txt'); reset(input);}
    read(n);
    top[1] := 0; top[2] := 0; top[3] := 0; h[1] := 1; h[2] := 1;
    h[3] := 1;
    for i := 1 to n do
    read(a[i].c);
    for i := 1 to n do
    read(a[i].c1);
    for i := 1 to n do
    read(a[i].c2);
    for i := 1 to n do
    begin
        inc(top[a[i].c1]);
        m[a[i].c1, top[a[i].c1]].i := a[i].c;
        m[a[i].c1, top[a[i].c1]].j := i;   
        if a[i].c1 <> a[i].c2 then
        begin 
        inc(top[a[i].c2]);
        m[a[i].c2, top[a[i].c2]].i := a[i].c;
        m[a[i].c2, top[a[i].c2]].j := i; 
        end;
    end;
    for i := 1 to 3 do
    if top[i] > 1 then
    sort(1, top[i], m[i]);
    read(k);
    
    for i := 1 to n do
    for j := 1 to 3 do
    b[j, i] := true;
    for i := 1 to 3 do
    for j := 1 to top[i] do
    if i = a[m[i, j].j].c1 then
        a[m[i, j].j].b1 := j
    else
        a[m[i, j].j].b2 := j;{
      for i := 1 to n do
    writeln(a[i].c, ' ', a[i].c1, ' ', a[i].b1, ' ', a[i].c2, ' ', a[i].b2);}
    for i := 1 to k do
    begin
        read(j);
        while (top[j] >= h[j]) and (not b[j, h[j]]) do inc(h[j]);
        if h[j] <= top[j] then
        begin
            writeln(m[j, h[j]].i); 
            j := m[j, h[j]].j; 
            b[a[j].c1, a[j].b1] := false;
            b[a[j].c2, a[j].b2] := false;
        end else
        writeln(-1);
    end;
end.