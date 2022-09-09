{$Q+,S+,R+,I+,O-}
{$mode delphi}

var mm,a:array[0..200000] of longint;
    n,i,l,r,m:longint;
    ans:array[0..200000] of longint;

function min(a,b:longint):longint;
begin
min:=a;
if b<a then min:=b;
end;

begin
// assign(input,'input.txt');
// reset(input);
read(n);
for i:=n downto 1 do read(a[i]);
mm[0]:=2000000000;
for i:=1 to n do mm[i]:=min(mm[i-1],a[i]);
// for i:=1 to n do writeln(mm[i]);
for i:=1 to n do begin
    l:=0;
    r:=i-1;
    while r-l>1 do begin
	  m:=(l+r) div 2;
	  if mm[m]>=a[i] then l:=m
			      else r:=m;
    end;
//     writeln(i,' ',r);
    if mm[r]>=a[i] then ans[i]:=-1
		    else ans[i]:=i-r-1;
end;
// assign(output,'output.txt');
// rewrite(output);
for i:=n downto 1 do write(ans[i],' ');
// close(output);
end.