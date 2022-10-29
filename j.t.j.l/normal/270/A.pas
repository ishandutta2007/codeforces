var
  n,i,x:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
     readln(x);
     if 360 mod (180-x)=0 then
       writeln('YES')
     else
       writeln('NO');
    end;
end.