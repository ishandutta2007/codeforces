var
 s1,s2,s3:string;
 n,m:integer;
 i,j:integer;
begin
 readln(n,m);
 setlength(s1,m);
setlength(s2,m);
setlength(s3,m);
 for i:=1 to m do
  begin
   s1[i]:=('#');
   s2[i]:=('.');
   s3[i]:=('.');
  end;
  s2[m]:=('#');
  s3[1]:=('#');
 for i:=1 to n do
  begin
   if i mod 2<>0 then writeln(s1) else
   if j=0 then begin j:=1; writeln(s2); end
   else begin j:=0; writeln(s3); end;
  end;
  end.