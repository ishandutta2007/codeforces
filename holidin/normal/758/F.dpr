program ps;  {$Q+ $R+}

var i, j, n, x, y, m: longint;   k, l, r: int64;

function nod(a, b: longint): longint;
begin
    if b = 0 then nod := a else nod := nod(b, a mod b);
end;

function sqrtn(n, r: longint): int64;
var i, j: longint; b: boolean; k: int64;
begin
    i := 1; b := true;
    while b do
    begin
        inc(i);
        k := 1;
        for j := 1 to n do
        if k <= r then
        k := k * i;
        b := k <= r;
    end;
    sqrtn := i - 1;
end;

function st(x, n: longint): int64;
var i: longint; j: int64;
begin
    j := 1;
    for i := 1 to n do
    j := j * x;
    st := j;
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    read(n, l, r);
    if n < 3 then
    begin
        if n = 1 then write(r - l + 1)
        else write((r - l + 1)*(r - l));
        halt(0);
    end;
    m := sqrtn(n - 1, r);
    k := 0;
    for y := 1 to m do
    for x := y + 1 to m do
    if nod(x, y) = 1 then
    if (r div st(x, n - 1)) - ((l - 1) div st(y, n - 1)) >= 0 then
    k := k + (r div st(x, n - 1)) - ((l - 1) div st(y, n - 1));
    write(k*2);
end.