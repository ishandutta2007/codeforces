var a : array[0 .. 42] of longint;
t : longint;
j : longint;
i, k, id, n : longint;
x : int64;
begin
read(x);
while (x > 0) do begin
a[n] := longint(x mod 10);
x := x div 10;
inc(n);
end;
read(k);
for i := n - 1 downto 0 do begin
id := -1;
for j := i downto 0 do begin
if i - j > k then break;
if (id < 0) or (a[id] < a[j]) then id := j;
end;
while id < i do begin
t := a[id];
a[id] := a[id + 1];
a[id + 1] := t;
dec(k);
inc(id);
end;
end;
for i := n - 1 downto 0 do write(a[i]);
writeln;
end.