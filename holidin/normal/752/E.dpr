program Project1; {$Q+ $R+}
const mod1 = 1000000;

var i, k, n: longint;  x, o, l, r, j: int64;
    m, s: array[0..1000000]of longint;



function f(i: longint): longint;
begin

    if i < 1000000 then
    begin
        if s[i] = -1 then
        if i < j then s[i] := 0 else if i < 2*j then s[i] := 1 else
    if i mod 2 = 0 then s[i] := 2*f(i div 2) else s[i] := f(i div 2) + f((i + 1) div 2);
       f := s[i];
    end else
    begin
    if i < j then f := 0 else if i < 2*j then f := 1 else
    if i mod 2 = 0 then f := 2*f(i div 2) else f := f(i div 2) + f((i + 1) div 2);
    end;
end;

function f1(j: int64): boolean;
var i: longint; o: int64;
begin
    o := 0;
    for i := 1 to 1000000 do
    s[i] := -1;
    for i := 1 to n do
    o := o + f(m[i]);
    f1 := o >= k;
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    readln(n, k);
    for i := 1 to n do
    begin
        read(m[i]);
        o := o + m[i];
    end;
    l := 1;
    r := 1 + (o div k);
    if r > 10000000 then r := 10000000 + 1;
    while l < r - 1 do
    begin
        x := (l + r) div 2;
        j := x;
        if f1(x) then
            l := x
        else
            r := x;
    end;
    j := 1;
    if f1(1) then
    write(l) else write(-1);
end.