var s:ansistring;
ww,cnt,x1,max,i,j:longint;
p,ff,a,b,d:array[0..1000001] of longint;
procedure add(x,y:longint);
begin
cnt:=cnt+1;a[cnt]:=y;b[cnt]:=d[x];d[x]:=cnt;
end;
begin
//assign(input,'bm.in');reset(input);
//assign(output,'bm.out');rewrite(output);
readln(s);
for i:=1 to length(s) do
      begin
      if s[i]='0' then begin x1:=x1+1;add(x1,i);ff[x1]:=ff[x1]+1;end
      else begin if x1=0 then begin writeln(-1);close(input);close(output);halt;end;add(x1,i);ff[x1]:=ff[x1]+1;x1:=x1-1;end;
      if x1>max then max:=x1;
      end;
if max<>x1 then begin writeln(-1);close(input);close(output);halt;end;
writeln(max);
for i:=1 to max do
     begin
     write(ff[i],' ');
     j:=d[i];ww:=0;
     while j>0 do
         begin
         ww:=ww+1;p[ww]:=a[j];
         j:=b[j];
         end;
     for j:=ww downto 1 do write(p[j],' ');
     writeln;
     end;
close(input);close(output);
end.