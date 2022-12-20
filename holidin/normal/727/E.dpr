program q;
const D1 = 33;
      D2 = 101*107*47;
      D3 = 51;
      MOD2 = 4096*4096;
      MOD1 = 1000000007;
      MOD3 = 999999997;
var m, a, m1: array[0..2000000]of int64;
    u: array[0..2000000]of record i, i1: int64; j: longint; end;
    i, j, k, n, g, l, r: longint; x, o, t, o1, t1: int64; s, s1: string;
    f: array[0..MOD2*2]of int64;

function hesh(a, o: int64): longint;
var i, j: int64;
begin
    i := (a * D2 + o);
    j := i;
    i := i mod MOD2;
    while f[i] mod j <> 0 do
    inc(i);
    hesh := i;
end;

procedure sort(first, last: longint);
var f, l, mid, mid1: longint;
begin
    f := first;
    l := last;
    mid := u[(f + l) div 2].i;
    mid1 := u[(f + l) div 2].i1;
    repeat
         while (u[f].i < mid) or ((u[f].i = mid) and (u[f].i1 < mid1)) do inc(f);
         while (u[l].i > mid) or ((u[l].i = mid) and (u[l].i1 > mid1)) do dec(l);
         if f <= l then
         begin
             u[0] := u[f];
             u[f] := u[l];
             u[l] := u[0];
             inc(f);
             dec(l);
         end;
    until f > l;
    if f < last then sort(f, last);
    if first < l then sort(first, l);
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    readln(n, k);
    readln(s);
    s := s + s;
    for i := 1 to length(s) do
    begin
        m[i] := (m[i - 1]*D1 + ord(s[i]) - ord('a')) mod MOD1;
        m1[i] := (m1[i - 1]*D3 + ord(s[i]) - ord('a')) mod MOD3;
    end;
    readln(g);
    for i := 1 to g do
    begin
        readln(s1);
        u[i].i := 0;
        for j := 1 to length(s1) do
        u[i].i := (u[i].i*D1 + ord(s1[j])-ord('a')) mod MOD1;
        for j := 1 to length(s1) do
        u[i].i1 := (u[i].i1*D3 + ord(s1[j])-ord('a')) mod MOD3;
        u[i].j := i;
    end;
    for i := n*k + 1 to 2*n*k do
    a[i] := 1;
    t := 1;
    for i := 1 to k do
    t := (t * D1) mod MOD1;
    t1 := 1;
    for i := 1 to k do
    t1 := (t1 * D3) mod MOD3;
    sort(1, g);
    for i := n*k downto 1 do
    begin
        l := 1;
        r := g + 1;
        o := (m[i + k - 1] - m[i - 1]*t + m[i -1]*MOD1) mod MOD1;
        o1 := (m1[i + k - 1] - m1[i - 1]*t1 + m1[i - 1]*MOD3) mod MOD3;
        while l <> r - 1 do
        begin
            x := (l + r) div 2;
            if (u[x].i > o) or ((u[x].i = o) and (u[x].i1 > o1)) then
                r := x
            else
                l := x;
        end;
        if (u[l].i1 = o1) and (u[l].i = o) and (a[i + k] > 0) and (f[hesh((i - 1) mod k, l)] = 0) then
        begin
            a[i] := u[l].j;
            f[hesh((i - 1) mod k, l)] := (1*(i - 1) mod k)  * D2 + l;
        end;
    end;
    for i := 1 to k do
        if a[i] > 0 then
        begin
            writeln('YES');
            for j := 0 to n - 1 do
            write(a[j*k + i], ' ');
            halt(0);
        end;
    writeln('NO');
end.