program q;
var a:array[1..200000]of longint; i,j,n,k:longint;
begin
   { assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    read(n);
    for i:=1 to 2*n do
    begin
       read(j);
       k:=j+k;
       inc(a[j]);
    end;
    n:=k div n;
    for i:=1 to n div 2 do
    begin
      while a[i]>0 do
      begin
         dec(a[i]);
         dec(a[n-i]);
         writeln(i,' ',n-i)
      end
    end;

end.