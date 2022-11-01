var
 w:array[1..200001] of integer;
 h:array[1..200001] of integer;
 n,i,maxi:longint;
 max,predmax:integer;
 wi,hi,s:int64;
begin
 readln(n);
 for i:=1 to n do
  begin
    readln(w[i],h[i]);
	inc(s,w[i]);
  end;
 for i:=1 to n do
   if h[i]>max then begin 
    predmax:=max; max:=h[i]; maxi:=i; end else
     if h[i]>predmax then predmax:=h[i];
  
  for i:=1 to n do
   begin
    wi:=s-w[i];
	if maxi<>i then hi:=max else hi:=predmax;
	write(wi*hi,' ');
   end;
   writeln();
end.