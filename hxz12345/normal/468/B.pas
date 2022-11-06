var i,n,x,y,r1,r2,r3:longint;
a,b,f:array[0..100001] of longint;
 procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                y:=b[i];b[i]:=b[j];b[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
function find(x:longint):longint;
begin
if f[x]=x then exit(f[x]);
f[x]:=find(f[x]);find:=f[x];
end;
function zh(x:longint):longint;
var t,w,mid:longint;
begin
t:=1;w:=n;
while t<=w do
    begin
    mid:=(t+w) div 2;
    if a[mid]=x then exit(b[mid]);
    if a[mid]>x then w:=mid-1
    else t:=mid+1;
    end;
exit(0);
end;
begin

readln(n,x,y);
for i:=1 to n do
    begin
    read(a[i]);
    b[i]:=i;
    end;
sort(1,n);
for i:=1 to n+2 do f[i]:=i;
for i:=1 to n do
     begin
     r1:=find(zh(a[i]));r2:=find(zh(x-a[i]));r3:=find(n+1);
     if r2>0 then f[r1]:=r2
     else f[r1]:=find(n+1);
     r1:=find(zh(a[i]));r2:=find(zh(y-a[i]));r3:=find(n+2);
     if r2>0 then f[r1]:=r2
     else f[r1]:=find(n+2);
     end;
if find(n+1)=find(n+2) then writeln('NO')
else
    begin
    writeln('YES');
    for i:=1 to n do
      if find(i)=find(n+1) then write(1,' ')
      else write(0,' ');
    end;

end.