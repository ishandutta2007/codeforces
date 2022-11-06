var n,k,l,r,sall,sk,i:integer;
begin
     readln(n,k,l,r,sall,sk);
     for i:=1 to sk mod k do write((sk div k)+1,' ');
     for i:=(sk mod k)+1 to k do write((sk div k),' ');
     if n<>k then begin
        for i:=1 to (sall-sk)mod(n-k) do write((sall-sk)div(n-k) +1,' ');
        for i:=(sall-sk)mod(n-k)+1 to n-k do write((sall-sk)div(n-k),' ');
     end;
end.