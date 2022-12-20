program u;
var n,i,j,k,a,b:longint; m:array[0..37,-37..37]of int64; c:char;
begin
{ assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
 } read(n);
  for i:=1 to n do
  begin
     c:=#0;
     while c<>' ' do
     read(c);
     readln(a,b);
     if (a>=2400) and (b>a)
     then k:=1
  end;
  if k=1
  then write('YES')
  else write('NO')
end.