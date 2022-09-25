{$APPTYPE CONSOLE}
var
  i,n,m,ans,j,l,r:integer;
  c:char;
  a,ans2:array[0..16]of string;
  b:array[0..300,1..2]of string;
  pair:array[0..16,0..16]of boolean;
  used,ans1:array[0..16]of boolean;
function check(x,k:integer):boolean;
var i:integer;
begin
  result:=false;
  for i:=1 to x do if (used[i])and(pair[i,k]) then result:=true;
end;
procedure rec(x,y:integer);
var i:integer;
begin
  if x=n then begin
    if ans<y then begin
      for i:=1 to n do ans1[i]:=used[i];
      ans:=y;;
    end;
  end else begin
    if not check(x,x+1) then begin
      used[x+1]:=true;
      rec(x+1,y+1);
    end;
    used[x+1]:=false;
    rec(x+1,y);
  end;
end;
procedure swap(var a,b:string);
var c:string;
begin
  c:=a; a:=b; b:=c;
end;
procedure qsort(l,r:integer);
var i,j:integer;
x:string;
begin
  i:=l; j:=r;
  x:=ans2[l+random(r-l)];
  repeat
    while ans2[i]<x do inc(i);
    while ans2[j]>x do dec(j);
    if i<=j then begin
      swap(ans2[i],ans2[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;
begin
//  reset(input,'input.txt');
//  rewrite(output,'output.txt');
  readln(n,m);
  for i:=1 to n do readln(a[i]);
  for i:=1 to n*(n-1)div 2 do begin
    b[i,1]:='';
    b[i,2]:='';
  end;
  for i:=1 to m do begin
    c:='a';
    while c<>' ' do begin
      read(c);if c<>' ' then  b[i,1]:=b[i,1]+c;
    end;
    c:='a';
    while not seekeoln do begin
      read(c); b[i,2]:=b[i,2]+c;
    end;
    for j:=1 to n do if a[j]=b[i,1] then l:=j;
    for j:=1 to n do if a[j]=b[i,2] then r:=j;
    pair[l,r]:=true;
    pair[r,l]:=true;
    readln;
  end;
  ans:=0;
  rec(0,0);
  writeln(ans);
  l:=0;
  for i:=1 to n do if ans1[i] then begin
    inc(l);
    ans2[l]:=a[i];
  end;
  qsort(1,ans);
  for i:=1 to ans do writeln(ans2[i]);
//  close(input);
//  close(output);
end.