type mas = array[0..1000000]of record st, kr: longint; end;

var a, b: mas;
     kr, st, i, j, l, r, k, max, max1, max2, x1, x2, top1, top2, n: longint;
     pr1, pr2: array[0..1000000]of longint; c: char;

procedure sort(first, last: longint; var m: mas);
var f, l, mid: longint;
begin
    f := first;
    l := last;
    mid := m[(f + l) div 2].st;
    repeat
         while m[f].st < mid do inc(f);
         while m[l].st > mid do dec(l);
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
    {assign(input, 'input.txt'); reset(input);}
    read(n, x1, x2); top1 := 0; top2 := 0;
    for  i := 1 to n do
    begin
        read(kr, st);
        read(c); read(c); readln;
        if c = 'C' then
        begin
            inc(top1);
            a[top1].kr := kr;
            a[top1].st := st;         
        end else
        begin
            inc(top2);
            b[top2].kr := kr;
            b[top2].st := st;
        end;
    end;
    max1 := 0; max2 := 0;
    for i := 1 to top1 do
    if (a[i].st <= x1) and (a[i].kr > max1) then max1 := a[i].kr;
    for i := 1 to top2 do
    if (b[i].st <= x2) and (b[i].kr > max2) then max2 := b[i].kr;
    if (max1 > 0) and (max2 > 0) then max := max1 + max2;
    sort(1, top1, a);
    pr1[1] := a[1].kr;
    for i := 2 to top1 do
    if pr1[i - 1] < a[i].kr then
        pr1[i] := a[i].kr
    else
        pr1[i] := pr1[i - 1];
    pr1[0] := 0;
    l := 1;
    for r := top1 downto 2 do  
    begin
        while (l < r) and (a[l].st <= x1 - a[r].st) do inc(l);
        if l > r then dec(l);
        if (l > 1) and (pr1[l - 1] + a[r].kr > max) then max := pr1[l - 1] + a[r].kr;
    end;  
    
    sort(1, top2, b);
    pr2[1] := b[1].kr;
    for i := 2 to top2 do
    if pr2[i - 1] < b[i].kr then
        pr2[i] := b[i].kr
    else
        pr2[i] := pr2[i - 1];
    pr2[0] := 0;
    l := 1;
    for r := top2 downto 2 do  
    begin
        while (l < r) and (b[l].st <= x2 - b[r].st) do inc(l);
        if l > r then dec(l);
        if (l > 1) and (pr2[l - 1] + b[r].kr > max) then max := pr2[l - 1] + b[r].kr;
    end; 
    writeln(max);
end.