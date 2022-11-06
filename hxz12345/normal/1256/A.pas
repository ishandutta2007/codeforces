var top,x1,y1,n,s:int64;
begin
readln(top);
while top>0 do
   begin
   readln(x1,y1,n,s);
   if n*x1>=s then
      begin
      s:=s mod n;
      if s<=y1 then writeln('YES')
      else writeln('NO');
      end
   else
      if s-n*x1<=y1 then writeln('YES')
   else writeln('NO');
   dec(top);
   end;
end.