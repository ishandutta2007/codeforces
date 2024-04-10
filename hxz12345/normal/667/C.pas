var s:ansistring;
a:array[0..100001] of string; 
ll,w,ww,i:longint;
f:array[0..100001,0..4] of boolean;
procedure sort(l,r: longint);
      var
         i,j: longint;
         x,y:string;
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
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
//assign(input,'yyx.in');reset(input);
//assign(output,'yyx.out');rewrite(output);
readln(s);
ll:=length(s);
if length(s)>=7 then
    begin
    f[length(s)-1,2]:=true;
    w:=w+1;a[w]:=s[length(s)-1]+s[length(s)];
    end;
if length(s)>=8 then
    begin
    f[length(s)-2,3]:=true;
    w:=w+1;a[w]:=s[length(s)-2]+s[length(s)-1]+s[length(s)];
    end;
s:=s+'/////';
for i:=ll-3 downto 6 do
   begin
   if(copy(s,i,2)<>copy(s,i+2,2))and(f[i+2,2]) or (f[i+2,3])then
        begin
        f[i,2]:=true;
        w:=w+1;a[w]:=copy(s,i,2);
        end;
   if(copy(s,i,3)<>copy(s,i+3,3))and(f[i+3,3]) or (f[i+3,2])then
        begin
        f[i,3]:=true;
        w:=w+1;a[w]:=copy(s,i,3);
        end;
   end;
sort(1,w);
for i:=1 to w do
   if a[i]<>a[i-1] then ww:=ww+1;
writeln(ww);
for i:=1 to w do
    if a[i]<>a[i-1] then writeln(a[i]);
close(input);close(output);
end.