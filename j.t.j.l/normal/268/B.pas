var
  n,i,tot:longint;
begin
  readln(n);
  tot:=0;
  for i:=1 to n-1 do
    tot:=tot+i*(n-i);
  writeln(tot+n);
end.