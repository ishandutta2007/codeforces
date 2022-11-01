var
 n:integer;
 i:integer;
 s:integer;
 x1,y1,x2,y2:integer;
begin
  readln(n);
  for i:=1 to n do
  begin
   readln(x1,y1,x2,y2);
   inc(s,(x2-x1+1)*(y2-y1+1));
  end;
  writeln(s);
end.