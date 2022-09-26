var i,s2,a,b,s3,j,ans,ans2,q:int64;

begin
read(a,b);
a:=a-1;
s2:=1;
q:=0;
while (s2<a) do 
begin
s2:=s2*2;
q:=q+1;
end;
s3:=1;
ans:=0;
while (s3<=a) do 
begin
while (s3*s2>a) do
begin
s2:=s2 div 2;
q:=q-1;
end;
ans:=ans+q+1;
s3:=3*s3;
end;

s2:=1;
q:=0;
while (s2<b) do 
begin
s2:=s2*2;
q:=q+1;
end;
s3:=1;
ans2:=0;
while (s3<=b) do 
begin
while (s3*s2>b) do
begin
s2:=s2 div 2;
q:=q-1;
end;
ans2:=ans2+q+1;
s3:=3*s3;
end;
writeln(ans2-ans);
end.