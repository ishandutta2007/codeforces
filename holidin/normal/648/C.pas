program q;
var a:array[0..101,0..101]of char; var i,j,n,k,m,x1,y1,x,y:longint;
begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);
   } readln(n,m);
    for i:=1 to n do
    begin
    for j:=1 to m do
    read(a[i,j]);
      readln
    end;
    for i:=1 to n do
    for j:=1 to m do
    if a[i,j]='S'
    then begin x1:=i; y1:=j end;
    x:=x1;
    y:=y1;
    repeat
       a[x1,y1]:='.';
       if a[x1,y1+1]='*'
       then begin write('R'); inc(y1) end
  else if a[x1,y1-1]='*'
       then begin write('L'); dec(y1) end
  else if a[x1-1,y1]='*'
       then begin write('U'); dec(x1) end
  else if a[x1+1,y1]='*'
       then begin write('D'); inc(x1) end;
    until (a[x1,y1-1]<>'*') and (a[x1-1,y1]<>'*') and (a[x1+1,y1]<>'*') and (a[x1,y1+1]<>'*');
   if x>x1
   then write('D');
   if x<x1
   then write('U');
   if y>y1
   then write('R');
   if y<y1
   then write('L')
end.