{$Q+,S+,R+,I+,O+}
{$mode delphi}

uses Math;

var a,k,kh,n,m,h,i:longint;
	ans:extended;

begin
//assign(input,'input.txt');
//reset(input);
//assign(output,'output.txt');
//rewrite(output);
read(n,m,h);
k:=0;
for i:=1 to m do begin
	read(a);
	if i=h then kh:=a;
	inc(k,a);
end;
dec(k);
dec(kh);
dec(n);
if k<n then begin
	writeln(-1);
	halt;
end;
ans:=0;
//writeln(k,' ',n,' ',KH);
if n>k-kh then begin
	writeln(1);
	halt;
end;
for i:=1 to n do begin
	ans:=ans+(1-ans)*kh/(k-i+1);
end;
writeln(ans:0:10);
close(input);
close(output);
end.