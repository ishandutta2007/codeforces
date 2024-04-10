program u;
var n,i,j,k,a,b:longint; m:array[0..37,-37..37]of int64; c:char;
begin
 { assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  }read(n);
  for i:=0 to n div 1234567 do
  for j:=0 to (n-i*1234567) div 123456 do
  if (n-i*1234567-j*123456) mod 1234=0
  then k:=1;
  if k=1
  then write('YES')
  else write('NO');
end.