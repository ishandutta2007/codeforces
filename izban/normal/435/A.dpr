var n, m : longint;
ans, cur : longint;
x : longint;

i : longint;
begin
read(n, m);
for i := 1 to n do begin
read(x);
if cur + x > m then begin
cur := x;
inc(ans);
end else cur := cur + x;
end;
if cur > 0 then inc(ans);
writeln(ans);
end.