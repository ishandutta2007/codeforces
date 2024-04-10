program fuck;
var
i,n,f,len,k: integer;
a: array[0..3000] of integer;
begin
read(n);
for i:=1 to n do read(a[i]);
f:=1;
for len:=n downto 1 do begin
    while a[len] > 0 do begin
        for k:=1 to len do if f = 1 then write('a') else write('b');
        f:=1-f;
        dec(a[len]);
        for i:=len-1 downto 1 do a[i]:=a[i]-(len-i+1);
    end;
end;
writeln('');
end.