{$APPTYPE CONSOLE}
var
  i,n,j,m:integer;
  ans:integer;
  a:array[1..10] of string;
function check(i,j:integer):boolean;
begin
  result:=false;
  if (i<n)and(a[i+1,j]='P') then result:=true;
  if (j<m)and(a[i,j+1]='P') then result:=true;
  if (i>1)and(a[i-1,j]='P') then result:=true;
  if (j>1)and(a[i,j-1]='P') then result:=true;
end;
begin
{$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
{$ENDIF}
  ans:=0;
  readln(n,m);
  for i:=1 to n do readln(a[i]);
  for i:=1 to n do
    for j:=1 to m do
      if (a[i,j]='W') and (check(i,j)) then inc(ans);
      writeln(ans);
{$IFNDEF ONLINE_JUDGE}
  close(input);
  close(output);
{$ENDIF}
end.