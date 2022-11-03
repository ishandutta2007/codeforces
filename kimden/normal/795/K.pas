program aaaaaaaaaaaaaa;
var s:string;
i: integer;
j: integer;
n: integer;
cur: integer;
begin
readln(n);
readln(s);
cur := 1;
for i:= 2 to n do
  begin
    if s[i] <> s[i - 1] then
    begin
      if((s[i-1] <> 'a') and(s[i-1] <> 'e') and(s[i-1] <> 'i') and(s[i-1] <> 'u') and(s[i-1] <> 'o') and(s[i-1] <>'y')) then
      begin
        for j := 1 to cur do write(s[i-1]);
      end else
      if ((cur = 2) and ((s[i-1] = 'e') or (s[i-1] = 'o'))) then
        begin
          write(s[i-1]);
          write(s[i-1]);
        end
      else
        begin
          write(s[i - 1]);
        end;
      cur := 1;
    end
    else
      inc(cur);
  end;
if((s[n] <> 'a') and(s[n] <> 'e') and(s[n] <> 'i') and(s[n] <> 'u') and(s[n] <> 'o') and(s[n] <>'y')) then
begin
for j := 1 to cur do write(s[n]);
end else
if ((cur = 2) and ((s[n] = 'e') or (s[n] = 'o'))) then
begin
  write(s[n]);
  write(s[n]);
end
else
begin
  write(s[n]);
end;
writeln();
end.