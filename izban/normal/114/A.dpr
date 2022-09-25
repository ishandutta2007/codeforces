{$APPTYPE CONSOLE}
var
  i,n,k,l,ans:integer;
begin
//  reset(input,'input.txt');
//  rewrite(output,'output.txt');
  read(k,l);
  if l<k then begin
    writeln('NO'); halt(0);
  end;
  ans:=0;
  while (l>k)and(l mod k=0) do begin
    l:=l div k;
    inc(ans);
  end;
  if l=k then begin
    writeln('YES');
    writeln(ans);
  end else writeln('NO');
//  close(input);
//  close(output);
end.