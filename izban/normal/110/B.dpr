{$APPTYPE CONSOLE}
var
  i,n:integer;
begin
{  reset(input,'input.txt');
  rewrite(output,'output.txt'); }
  read(n);
  for i:=1 to n do begin
    case i mod 4 of
      1: write('a');
      2: write('b');
      3: write('c');
      0: write('d');
    end;
  end;
{  close(input);
  close(output);}
end.