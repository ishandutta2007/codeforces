var
 a,b:longint;
 teams:int64;
begin
 readln(a,b);
 while (a>0) and (b>0) do
  begin
    if a>b then
     begin
      dec(a,2);
      dec(b,1);
     end else
     begin
      dec(a,1);
      dec(b,2);
     end;
     if (a>=0) and (b>=0) then
     inc(teams);
  end;
  writeln(teams);
end.