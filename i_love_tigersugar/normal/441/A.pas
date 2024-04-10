program CFA;
var
        a:array [1..55] of longint;
        n,np,t,v,max,all,i,j:longint;
begin
        read(n,all);
        for i:=1 to n do
                begin
                        read(t);
                        for j:=1 to t do
                                begin
                                        read(v);
                                        if (j=1) or (max>v) then max:=v;
                                end;
                        if max<all then
                                begin
                                        inc(np);
                                        a[np]:=i;
                                end;
                end;
        writeln(np);
        if np=0 then halt;
        for i:=1 to np do
                begin
                        if i>1 then write(' ');
                        write(a[i]);
                end;
end.