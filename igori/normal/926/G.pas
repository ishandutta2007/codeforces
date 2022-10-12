var i,n,k, x, a1, a2, sol:longint;

begin
readln(n);
a1 := 0;
a2 := 0;
for i:=1 to n do 
begin
    read(x);
    if x mod 2 = 0 then a1 := a1 + 1;
    if x mod 2 = 1 then a2 := a2 + 1;
end;
if a2 <= a1 then
    write(a2)
else
    begin
       sol := a1;
       a2 := a2 - a1;
       sol := sol + a2 div 3;
       write(sol)
    end;

end.