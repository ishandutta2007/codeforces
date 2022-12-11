var
    x,y:array[0..200000] of longint;
    n,i,j,k1,k2:longint;
    s:ansistring;
begin
    readln(s);
    n:=length(s);
    for i:=1 to n do x[i]:=ord(s[i])-ord('0');
    readln(s);
    for i:=1 to n do y[i]:=ord(s[i])-ord('0');
    k1:=0; k2:=0;
    for i:=1 to n do 
        if x[i]<>y[i] then begin
            if x[i]=4 then inc(k1) else inc(k2);
        end;
    if k1>k2 then writeln(k1) else writeln(k2);
end.