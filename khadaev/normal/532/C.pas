var
  xp,yp,xv,yv, lp, lv:longint;
  
function max(a,b:longint):longint;
  begin
    if a > b then
      max := a
    else
      max := b;
  end;

begin
  read (xp,yp,xv,yv);
  lv := max (xv,yv);
  lp := xp + yp;
  if (lp <= lv) or ((xp <= xv) and (yp <= yv)) then
    write ('Polycarp')
  else
    write ('Vasiliy');
end.