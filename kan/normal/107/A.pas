{$Q+,S+,R+,I+,O+}
{$mode delphi}

uses Math;

const inf=1000000000;

var was:array[1..1000] of boolean;
	fl,f:array[1..1000] of longint;
	a,b,c,n,m,i,cur,maxf:longint;
	ans:longint;

begin
//assign(input,'input.txt');
//reset(input);
//assign(output,'output.txt');
//rewrite(output);
read(n,m);
fillchar(f,sizeof(f),0);
for i:=1 to n do was[i]:=false;
for i:=1 to m do begin
	read(a,b,c);
	f[a]:=b;
	fl[a]:=c;
	was[b]:=true;
end;
ans:=0;
for i:=1 to n do if (not was[i])and(f[i]<>0) then inc(ans);
writeln(ans);
for i:=1 to n do if (not was[i])and(f[i]<>0) then begin
	maxf:=inf;
	cur:=i;
	while f[cur]<>0 do begin
		maxf:=min(maxf,fl[cur]);
		cur:=f[cur];
	end;
	writeln(i,' ',cur,' ',maxf);
end;
//close(input);
//close(output);
end.