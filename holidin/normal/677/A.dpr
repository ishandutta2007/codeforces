program q;
var i,j,h,k,n:longint;
begin
 { assign(input,'input.txt'); reset(Input);
  assign(output,'output.txt'); rewrite(output);
  }read(n,h);
  k:=0;
  for i:=1 to n do
  begin
    read(j);
    if j>h
    then inc(k)
  end;
  write(n+k);
end.