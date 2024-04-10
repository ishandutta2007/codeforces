{$APPTYPE CONSOLE}
var
  i,n,a,b:integer;
begin
{  reset(input,'input.txt');
  rewrite(output,'output.txt');      }
  read(n,a,b);
  if ((a=n div 2)or(a=n div 2+1))and((b=n div 2)or(b=n div 2+1)) then begin
    writeln('NO');
  end else begin
//    if (a=2)or(b=2) then writeln('NO') else 
    writeln('YES');
  end;
{  close(input);
  close(output);  }
end.