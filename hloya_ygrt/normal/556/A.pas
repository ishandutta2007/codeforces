var
 a:ansistring;
 i:longint;
 one,nilll:longint;
 n:longint;
begin
 readln(n);
readln(a);
 for i:=1 to n do
  if a[i]=('1') then inc(one) else inc(nilll);
 writeln(abs(one-nilll));
end.