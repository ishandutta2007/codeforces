{$APPTYPE CONSOLE}
uses math;
var
  N,i,j:integer;
  s:string;
procedure up(var c:char);
begin
  if (c>='A')and(c<='Z') then c:=chr(ord(c)-ord('A')+ord('a'));
end;
function gl(c:char):boolean;
begin
  result:=(c='a')or(c='o')or(c='y')or(c='e')or(c='u')or(c='i');
end;
begin
//reset(input,'house.in');
//rewrite(output,'house.out');
//  reset(input,'input.txt');
//  rewrite(output,'output.txt');
  readln(s);
  n:=length(s);
  for i:=1 to n do begin
    up(s[i]);
  end;
  i:=1;
  while i<=n do begin
    if gl(s[i]) then begin
      delete(s,i,1);
      dec(n);
      dec(i);
    end;
    inc(i);
  end;
  for i:=1 to n do write('.',s[i]);
  close(input);
  close(output);
end.