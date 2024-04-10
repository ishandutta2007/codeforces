{$APPTYPE CONSOLE}
var
  i,n,x,y,a,b:integer;
function gcd(a,b:integer; var x,y:integer):integer;
var x1,y1,d:integer;
begin
  if (a=0) then begin
    x:=0; y:=1; result:=b; exit;
  end;
  d:=gcd(b mod a,a,x1,y1);
  x:=y1-(b div a)*x1;
  y:=x1;
  result:=d;
end;
begin
{  reset(input,'input.txt');
  rewrite(output,'output.txt');}
  read(n);
  gcd(4,7,x,y); a:=4; b:=7;
  x:=x*n; y:=y*n;
  if a<b then begin
    while x>0 do begin
      x:=x-b; y:=y+a;
    end;
  end else begin
     while y>0 do begin
       x:=x+b; y:=y-a;
     end;
  end;
  if y<0 then begin
    x:=x-b; y:=y+a;
  end;
  if x<0 then begin
    x:=x+b; y:=y-a;
  end;
  if (x>=0)and(y>=0)and(x*4+y*7=n) then begin
    for i:=1 to x do write(4);
    for i:=1 to y do write(7);
  end else write(-1);
  {x:=n div 4;
  while ((n-x*4)mod 7<>0)and(x>=0) do begin
    dec(x);
  end;
  if ((n-x*4)mod 7=0)and(x>-1) then y:=(n-x*4)div 7 else y:=-100;
  if (y>-100)and(x*4+y*7=n) then begin
    for i:=1 to x do write(4);
    for i:=1 to y do write(7);
  end else write(-1);  }
{  close(input);
  close(output);}
end.