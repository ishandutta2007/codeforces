var
s,n1,n2:string;
map:array[1..210] of string;
q:array[1..40001] of integer;
min:array[1..210] of integer;
matrix:array[1..210,1..210] of boolean;
n,l,r,max,i,x1,j,i1,i2:integer;
f1:text;
 function ravn(var s1,s2:string):boolean;
 var
 k:integer;
 umen,uvel:string;
 length1,length2:integer;
 er:integer;
 begin
 er:=0;
 length1:=length(s1);
 length2:=length(s2);
 if length1<>length2 then begin ravn:=false; exit; end
 else
 for k:=1 to length1 do
  begin
   umen:=chr(ord(s2[k])-32);
   uvel:=chr(ord(s2[k])+32);
   if (s1[k]<>s2[k]) and (s1[k]<>uvel) and (s1[k]<>umen) then begin er:=1; break; end;
  end;
  if er=0 then ravn:=true else ravn:=false;
 end;

 begin

  readln(n);
  for i1:=1 to n do
  begin
   readln(s);
   i2:=0;
   while true do
   begin
    inc(i2);
	if s[i2]=(' ') then break;
   end;

   n1:=copy(s,1,i2-1);
   n2:=copy(s,i2+10,length(s)-(i2+10)+1);

   if x1=0 then begin inc(x1,2); map[1]:=n2; map[2]:=n1; i:=2; j:=1; end else
   begin
    for i:=1 to x1 do
     if ravn(n1,map[i])=true then break;
     if (x1=i) and (ravn(n1,map[x1])=false) then
	 begin inc(x1); map[x1]:=n1; i:=x1; end;
	for j:=1 to x1 do
	 if ravn(n2,map[j])=true then break;
   end;

   matrix[j,i]:=true;

  end;
  q[1]:=1;
  min[1]:=1;
  l:=1;
  r:=1;
  while l<=r do
   begin
    for i:=1 to x1 do
	 if matrix[q[l],i]=true then
	  if min[i]=0 then begin
	     inc(r); q[r]:=i; min[i]:=min[q[l]]+1;
	   end;
	  inc(l);
   end;
   for i:=1 to x1 do
   if max<min[i] then max:=min[i];
   writeln(max);

 end.