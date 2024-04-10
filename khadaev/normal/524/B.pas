var
n,mh,s,p,i,j:longint;
x:array[1..1024,1..4] of longint;

function minc(a,b:longint):longint;
 begin
  if a < b then
    minc := a
  else
    minc := b;
 end;

begin
  read(n);
  for i := 1 to n do
    begin
      read(x[i,1],x[i,2]);
      mh := minc(x[i,1], x[i,2]);
      x[i,2] := x[i,1] + x[i,2] - mh;
      
      x[i,1] := mh;      
    end;
  
  p := 1000000001;
  
  for i := 1 to n do
    begin
      s := 0;
      j:=1;
      while (x[j,1] <= x[i,1]) and (j <= n) do
        begin
          if x[j,2] <= x[i,1] then
            s := s + x[j,1]
          else
            s := s + x[j,2];          
          inc(j);
        end;            
        if (j = (n + 1)) and ((s * x[i,1]) < p) then
              p := s * x[i,1];
            
      
      s := 0;
      j:=1;
      while (x[j,1] <= x[i,2]) and (j <= n) do
        begin
          if x[j,2] <= x[i,2] then
            s := s + x[j,1]
          else
            s := s + x[j,2];          
          inc(j);
        end;            
        if (j = n + 1) and (s * x[i,2] < p) then
              p := s * x[i,2];
            
      
      
      
      
    end;


write (p);
end.