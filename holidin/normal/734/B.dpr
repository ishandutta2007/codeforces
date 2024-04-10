program q;
var i, a, b, c, d, o: longint;

function min(a, b: longint): longint;
begin
    if a < b then min := a else min := b;
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    read(b, a, c, d);
    o :=min(min(b, c), d);
    i := o * 256 + min(b - o, a)*32;
    write(i);
end.