program q;    {$Q- $R-}
const m:array[1..25]of longint=
(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97);
var i,j,k,a,t,n:longint;   s:string;

Begin
 { assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  } i:=1;
  j:=100;
  t:=20;
  while (i<=25) and (m[i]<=j) and (t>0) do
  begin
    a:=1;
    while (a>0) and (m[i]<=j) do
    begin
      a:=a*m[i];
      dec(t);
      writeln(a);
      flush(output);
      readln(s);
      if s='yes'
      then begin inc(k); j:=j div m[i] end
      else  a:=0
    end;
    inc(i)
  end;
  if k>1
  then writeln('composite')
  else writeln('prime');
  flush(output);
end.