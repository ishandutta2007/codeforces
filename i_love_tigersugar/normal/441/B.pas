program CFB;
const MAXN=3333;
var
        s:array[1..MAXN] of longint;
        n,v,i,a,b,res,prev:longint;
begin
        read(n,v);
        for i:=1 to n do
                begin
                        read(a,b);
                        s[a]:=s[a]+b;
                end;
        res:=0;
        prev:=0;
        for i:=1 to MAXN-100 do
                begin
                        if prev+s[i]<=v then
                                begin
                                        res:=res+prev+s[i];
                                        prev:=0;
                                end
                        else
                                begin
                                        res:=res+v;
                                        if prev>=v then prev:=s[i] else prev:=s[i]-v+prev;
                                end;
                end;
        write(res);
end.