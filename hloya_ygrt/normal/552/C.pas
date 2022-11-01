
  var
  w,m:longint;
  checkres:longint;
  v1:longint;
  procedure check(var m1,w1:longint);
   begin
    if m1=1 then checkres:=1 else
    if m1 mod w1=0 then begin v1:=m1 div w1; check(v1,w1); end else
    if (m1-1) mod w1=0 then begin v1:=(m1-1) div w1; check(v1,w1); end else
    if (m1+1) mod w1=0 then begin v1:=(m1+1) div w1; check(v1,w1); end;
   end;
  begin

     readln(w,m);
     if w=2 then writeln('YES') else
     begin
      check(m,w);
      if (checkres=1) then writeln('YES') else
      writeln('NO');
     end;

   end.