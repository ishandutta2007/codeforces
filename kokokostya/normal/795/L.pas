var
  s: string;
  i, n, k, l, r, m, sol, now, used: integer;
  a: array[0.. 200001] of integer;

begin
  readln(n, k);
  readln(s);
  l := 0; r := n;
  k := k - 2;
  now := 0;
  sol := 0;
  for i := 2 to n - 1 do
  begin
    if(s[i] = '1') then
    begin
      now := now + 1;
    end
    else
    begin
      if(now <> 0) then
      begin
        a[sol] := now;
        sol := sol + 1;
        now := 0;
      end;
      a[sol] := -1;
      sol := sol + 1;
    end;
    
  end;
  
  if(now <> 0) then
  begin
    a[sol] := now;
    sol := sol + 1;
    now := 0;
  end;
  
  while l <> r do
  begin
    m := (l + r) div 2;
    now := 0;
    used := k;
    for i := 0 to sol - 1 do
    begin
      
      if(a[i] > 0) then
      begin
        if(now + a[i] > m) then
        begin
          now := a[i];
          used := used - 1;
        end
        else
        begin
          now := now + a[i];
        end
        
      end
      else
      begin
        if(now = m) then
        begin
        now := 0;
        used := used - 1;
        end
        else
        now := now + 1;
      end;
      
      if(now > m) then
        used := -1;
    end;
    
    if(used >= 0) then
      r := m
    else
      l := m + 1;
    
  end;
  writeln(l);
end.