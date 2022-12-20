program q;    {$Q- $R-}
var i,j,k,a,t:longint;
 m:array[1..100]of longint;
Begin
 {assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  }for i:=1 to 5 do
  begin
    read(a);
    inc(m[a]);
    t:=t+a;
  end;
  k:=t;
  for i:=1 to 100 do
  if (m[i]=2)
  then if t-2*i<k
       then k:=t-2*i
       else
  else if m[i]>2
       then if t-3*i<k
            then k:=t-3*i;
  write(k)
end.