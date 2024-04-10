{$Q+,S+,R+,I+,O-}
{$mode delphi}

uses Math;

var a:array[1..100] of longint;
	ans:int64;
	i,n:longint;

begin
{assign(input,'input.txt');
reset(input);
assign(output,'output.txt');
rewrite(output);}
readln(n);
for i:=1 to n do begin
	read(a[i]);
end;
ans:=n;
for i:=1 to n do ans:=ans+int64(a[i]-1)*i;
writeln(ans);
close(input);
close(output);
end.