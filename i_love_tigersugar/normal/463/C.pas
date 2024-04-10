program TaskC;
const
        maxn=2222;
var
        a:array[-1..maxn,-1..maxn] of int64;
        da:array[0..2*maxn] of int64;
        ds:array[1-maxn..maxn-1] of int64;
        n:integer;
procedure init;
        var
                i,j:integer;
        begin
                read(n);
                for i:=1 to n do
                        for j:=1 to n do
                                begin
                                        read(a[i,j]);
                                        da[i+j]:=da[i+j]+a[i,j];
                                        ds[i-j]:=ds[i-j]+a[i,j];
                                end;
        end;
procedure maximize(var x:int64;y:int64);
        begin
                if x<y then x:=y;
        end;
procedure process;
        var
                i,j,x0,y0,x1,y1:integer;
                max:array[0..33] of int64;
        begin
                for i:=0 to 1 do max[i]:=0;
                for i:=1 to n do
                        for j:=1 to n do
                                maximize(max[(i+j) mod 2],da[i+j]+ds[i-j]-a[i,j]);
                writeln(max[0]+max[1]);
                for i:=1 to n do
                        for j:=1 to n do
                                if ((i+j) mod 2=0) and (max[0]=da[i+j]+ds[i-j]-a[i,j]) then
                                        begin
                                                x0:=i;
                                                y0:=j;
                                        end;
                for i:=1 to n do
                        for j:=1 to n do
                                if ((i+j) mod 2=1) and (max[1]=da[i+j]+ds[i-j]-a[i,j]) then
                                        begin
                                                x1:=i;
                                                y1:=j;
                                        end;
                write(x0,' ',y0,' ',x1,' ',y1);
        end;
begin
        init;
        process;
end.