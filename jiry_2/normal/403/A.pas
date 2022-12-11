program p01;
    var
        n,t,k,i,j,p,now:longint;
    begin
        readln(t);
        for k:=1 to t do begin
            readln(n,p); now:=0;
            for i:=1 to n do
                for j:=i+1 to n do
                    if now<n*2+p then begin 
                        inc(now); writeln(i,' ',j);
                    end;
        end;
    end.