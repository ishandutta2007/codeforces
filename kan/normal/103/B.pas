{$Q+,S+,R+,I+,O+}
{$mode delphi}

uses Math;

var gr:array[1..100,1..100] of longint;
	was:array[1..100] of longint;
	x,y:longint;
	n,m,i,kw:longint;

procedure go(cur,p:longint);
var i:longint;
begin
//writeln('go ',cur,' ',was[cur]);
if was[cur]<>0 then begin
	inc(kw);
	exit;
end;
was[cur]:=1;
for i:=1 to n do if (was[i]<2)and(gr[cur,i]=1)and(i<>p) then go(i,cur);
was[cur]:=2;
end;

begin
{assign(input,'input.txt');
reset(input);
assign(output,'output.txt');
rewrite(output);}
fillchar(gr,sizeof(gr),0);
readln(n,m);
for i:=1 to m do begin
	read(x,y);
	gr[x,y]:=1;
	gr[y,x]:=1;
end;
kw:=0;
go(1,-1);
for i:=1 to n do if was[i]=0 then kw:=0;
if kw=1 then writeln('FHTAGN!')
	else writeln('NO');
close(input);
close(output);
end.