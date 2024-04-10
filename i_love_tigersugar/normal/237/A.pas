program TaskA;
var
        res,cnt,prev,cur,n,i:integer;
function getTime:integer;
        var
                h,m:integer;
        begin
                read(h,m);
                exit(60*h+m);
        end;
begin
        read(n);
        res:=0;
        for i:=1 to n do
                begin
                        cur:=getTime;
                        if (i>1) and (cur=prev) then inc(cnt) else cnt:=1;
                        if res<cnt then res:=cnt;
                        prev:=cur;
                end;
        write(res);
end.