var
  i,n,m:longint;

begin
  readln(n,m);
  if n<m then
    begin
      writeln(n+1);
      for i:=0 to n do
        writeln(i,' ',n-i);
    end
  else
    begin
      writeln(m+1);
      for i:=0 to m do
        writeln(i,' ',m-i);
    end;
end.