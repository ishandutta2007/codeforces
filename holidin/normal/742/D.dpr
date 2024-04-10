program Project1; {$Q+ $R+}


type mas=array[0..30]of longint;

var
  a, m: array[0..1000000]of record i, j, k, o, w, b: longint; end;
  s: array[0..1000, 0..1000]of longint;
  i, j, k, n, w, max, l, r, sumb, sumw, top, top1: longint;

function nod(a, b: int64): int64;
begin
    if b = 0 then nod := a else nod := nod(b, a mod b);
end;

procedure bfs(i, j: longint);
var k, o1: longint;
begin
    k := a[i].i;
    a[i].o := j;
    for o1 := 0 to w do
    if (o1 + a[i].w <= w) and (s[j - 1, o1] + a[i].b > s[j, a[i].w + o1]) then
    s[j, a[i].w + o1] := s[j - 1, o1] + a[i].b;
    sumw := sumw + a[i].w;
    sumb := sumb + a[i].b;
    while k <> 0 do
    begin
        if a[m[k].i].o <> j then bfs(m[k].i, j);
        k := m[k].j;
    end;
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    read(n, k, w);
    for i := 1 to n do
    read(a[i].w);
    for i := 1 to n do
    read(a[i].b);
    for i := 1 to  k do
    begin
        read(l, r);
        if a[l].i = 0 then
        begin
            inc(top);
            a[l].i := top;
            m[top].i := r;
            a[l].j := top;
        end else
        begin
            inc(top);
            m[a[l].j].j := top;
            a[l].j := top;
            m[top].i :=  r;
        end;
        j := l;
        l := r;
        r := j;
        if a[l].i = 0 then
        begin
            inc(top);
            a[l].i := top;
            m[top].i := r;
            a[l].j := top;
        end else
        begin
            inc(top);
            m[a[l].j].j := top;
            a[l].j := top;
            m[top].i :=  r;
        end;
    end;
    top1 := 0;
    for i := 1 to n do
    if a[i].o = 0 then
    begin
        inc(top1);
        sumw := 0;
        sumb := 0;
        bfs(i, top1);
        for j := 0 to w do
        if (j + sumw <= w) and (s[top1 - 1, j] + sumb > s[top1, j + sumw]) then
            s[top1, j + sumw] := s[top1 - 1, j] + sumb;
        for j := 0 to w do
        if s[top1 - 1, j] > s[top1, j] then s[top1, j] := s[top1 - 1, j];
    end;
    max := 0;
    for i :=  1 to w do
    if s[top1, i] > max then max := s[top1, i];
    write(max);
end.