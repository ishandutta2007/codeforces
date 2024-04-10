var
  t,m,k,i,j,n0,q,y,x:longint;
  d,a:array[1..110000] of longint;
  b,r:array[1..110000] of shortint;
begin
  readln(t);
  readln;
  for i := 1 to t do
    begin
      read (m,k);
      for j := 1 to k do
        begin
          read(a[j]);
          b[j] := 1;
        end;
      for j := 1 to m - 1 do
       readln(d[j], r[j]);
      if i <> t then
        readln;
      n0 := 0;
      j := 1;
      while (r[j] = 0) and (j <= m - 1) do
        begin
          if d[j] = 0 then
            inc(n0)
          else
            dec(a[d[j]]);
          inc(j);
        end;
      if j = m then
        begin
          for q := 1 to k do
            if n0 >= a[q] then
              write('Y')
            else
              write('N');
          writeln;    
        end
        else
        begin
          y := j;
          for j := y to m - 1 do
            if d[j] <> 0 then
              b[d[j]] := 0;
          x :=100001;
          for j := 1 to k do
            if (a[j] < x) and (b[j] = 1) then
              begin
                x := a[j];
              end; 
          for j := 1 to k do
            if (a[j] <= n0) and (b[j] = 1) then
              a[j] := -1;
          for j := y to m - 1 do
            if d[j] = 0 then
              inc(n0)
            else
              dec(a[d[j]]);
          for j := 1 to k do
            if n0 - x >= a[j] then
              write('Y')
            else
              write('N');
          writeln;    
        end;
    end;        
end.