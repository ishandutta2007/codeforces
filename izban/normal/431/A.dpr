var
i : longint;

ans : longint;
a : array[0 .. 42] of longint;
c : char;

begin
for i := 1 to 4 do read(a[i]);
read(c);
while not (c in ['1' .. '4']) do read(c);
ans := 0;
while ord(c) >= 32 do begin
ans := a[ord(c) - ord('0')] + ans;
read(c);
end;
writeln(ans);
end.