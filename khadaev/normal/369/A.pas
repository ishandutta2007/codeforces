var n,m,k,c,i,a:integer;
begin
     readln(n,m,k);
     c:=0;
     for i:=1 to n do begin
         read(a);
         if a=1 then
            if m>0 then dec(m)
            else inc(c)
         else
             if k>0 then dec(k)
             else
                 if m>0 then dec(m)
                 else inc(c);
     end;
     writeln(c);
end.