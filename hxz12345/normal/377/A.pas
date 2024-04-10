const d:array[1..4,1..2] of longint=((-1,0),(1,0),(0,1),(0,-1));
var sum,l,t,w,n,m,k,i,j,s,x1,y1:longint;
b,c:array[0..250001] of longint;
a:array[0..501,0..501] of char;
f:array[0..501,0..501] of boolean;
begin
//assign(input,'mazewg.in');reset(input);
//assign(output,'mazewg.out');rewrite(output);  
readln(n,m,k);
for i:=1 to n do
   begin
   for j:=1 to m do
      begin
      read(a[i,j]);
      if a[i,j]='.' then begin s:=s+1;b[1]:=i;c[1]:=j;sum:=1;end;
      end;
   readln;
   end;
 f[b[1],c[1]]:=true;
if s=k+1 then
   begin
   for i:=1 to n do
      begin
      for j:=1 to m do
        if(a[i,j]='.')and(f[i,j]=false)then
          write('X')
      else write(a[i,j]);
      writeln;
      end;
   close(input);close(output);halt;
   end;
t:=1;w:=1;
while t<=w do
   begin
   for l:=1 to 4 do
      begin
      x1:=b[t]+d[l,1];y1:=c[t]+d[l,2];
      if(x1>=1)and(x1<=n)and(y1>=1)and(y1<=m)and(a[x1,y1]='.')and(f[x1,y1]=false)then
           begin
           w:=w+1;b[w]:=x1;c[w]:=y1;f[x1,y1]:=true;sum:=sum+1;
           if(sum=s-k)then
              begin
              for i:=1 to n do
                 begin
                 for j:=1 to m do
                    if(a[i,j]='.')and(f[i,j]=false)then
                        write('X')
                 else write(a[i,j]);
                 writeln;
                 end;
              close(input);close(output);halt;
              end;
           end;
   end;
   t:=t+1;
   end;
close(input);close(output);
end.