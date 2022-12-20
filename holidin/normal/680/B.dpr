program q;    {$Q- $R-}
var i,j,k,a,t,n:longint;
 m:array[1..100]of longint;
Begin
 { assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  }read(n,a);
  for i:=1 to n do
  read(m[i]);
  if m[a]=1
  then inc(k);
  i:=1;
  while (a-i>0) and (a+i<=n) do
  begin
    if m[a-i]=m[a+i]
    then k:=k+m[a-i]+m[a+i];
    inc(i)
  end;
  if a-i=0
  then while a+i<=n do
       begin
          k:=k+m[a+i];
          inc(i)
        end
  else while a-i>0 do
       begin
          k:=k+m[a-i];
          inc(i)
        end;
  write(k);
end.