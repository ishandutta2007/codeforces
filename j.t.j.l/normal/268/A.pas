var
  n,i,j,tot:longint;
  a,b:array [0..1001] of longint;
begin
  readln(n);
  for i:=1 to n do
    readln(a[i],b[i]);
  tot:=0;
  for i:=1 to n do
    for j:=1 to n do
      if i<>j then
        if a[i]=b[j] then
          inc(tot);
  writeln(tot);
end.