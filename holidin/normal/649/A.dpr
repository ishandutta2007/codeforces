program q;
var m:array[1..100]of longint; o,r,i,n,j:longint;
begin
   { assign(input,'input.txt'); reset(input);
    assign(output,'output.txt'); rewrite(output);
    }read(n);
    for i:=1 to n do
    read(m[i]);
    r:=1;
    for i:=1 to n do
    while  m[i] mod (r*2)=0 do
    r:=r*2;
    write(r,' ');
    o:=0;
    for i:=1 to n do
    if m[i] mod r=0
    then inc(o);
    write(o)
end.