{$APPTYPE CONSOLE}
var
  i,count:integer;
  s:string;
function f(x:Integer):boolean;
begin
   result:=(x=7)or(x=4);
end;
begin
{  reset(input,'input.txt');
  rewrite(output,'output.txt');}
  readln(s);
  count:=0;
  for i:=1 to length(s) do if (s[i]='4')or(s[i]='7') then inc(count);
  if count<10 then
    if f(count) then write('YES') else write('NO')
  else
    if (f(count mod 10))and(f(count div 10)) then write('YES') else write('NO');
{  close(input);
  close(output);}
end.