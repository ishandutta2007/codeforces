program q;
var i,j,k,n,m,o,h,p:int64;
begin
 { assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  }read(n,h,k);
  i:=0;
  j:=0;
  m:=0;
  read(p);
  while (j<n) or (m>0) do
  begin
     while (j<n) and (m+p<=h) do
     begin
       m:=m+p;
       inc(j);
       if n<>j
       then read(p);
     end;
     if m>k
     then begin i:=i+m div k; m:=m mod k end
     else begin m:=0; inc(i);   end
  end;
  write(i);
end.