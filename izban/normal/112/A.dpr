{$APPTYPE CONSOLE}
uses math,sysutils;
var
  i,n:integer;
  a,b:string;
procedure up(var s:char);
begin
  if (s<='z')and(s>='a') then s:=chr(ord(s)-ord('a')+ord('A'));
end;
begin
{  reset(input,'input.txt');
  rewrite(output,'output.txt');     }
  readln(a);
  readln(b);
  for i:=1 to length(a) do begin
    up(a[i]);
    up(b[i]);
  end;
  for i:=1 to min(length(a),length(b)) do begin
    if a[i]<b[i] then begin
      writeln(-1); halt(0);
    end else if a[i]>b[i] then begin
      writeln(1); halt(0);
    end;
  end;
  writeln(0);
//  close(input);
//  close(output);
end.