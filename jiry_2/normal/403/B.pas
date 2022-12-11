program p2;
    var
        a,b,c:array[0..6000] of longint;
        i,j,n,m,now,tot,k,min,k1,k2,k3,ans,pre,num:longint;
        x:array[0..40000] of longint;
        pd:array[0..40000] of boolean;
    function find(kk:longint):longint;
        var
            num,i,j,now:longint;
        begin
            num:=0; now:=kk;
            for i:=1 to k do begin
                if (x[i]>trunc(sqrt(kk))) or (now=1) then break;
                while now mod x[i]=0 do begin
                    inc(num); now:=now div x[i];
                end;
            end;
            if now<>1 then num:=num+1; exit(num);
        end;
    function gcd(k1,k2:longint):longint;
        begin
            if k2=0 then exit(k1);
            exit(gcd(k2,k1 mod k2));
        end;
    begin
        fillchar(pd,sizeof(pd),false);
        now:=0;
        for i:=2 to 35000 do
            if pd[i]=false then begin
                inc(now); x[now]:=i; j:=i;
                while j<=35000 do begin
                    pd[j]:=true; j:=i+j;
                end;
            end;
        k:=now;
        readln(n,m);
        for i:=1 to n do read(a[i]);
        for i:=1 to m do read(b[i]);
        ans:=0;
        for i:=1 to n do
            for j:=1 to m do begin
                now:=a[i];
                while now mod b[j]=0 do begin
                    inc(ans); now:=now div b[j];
                end;
            end;
        tot:=0; 
        for i:=1 to n do tot:=tot+find(a[i]);
        tot:=tot-ans*2;
        now:=a[1]; min:=0; pre:=0;
        for i:=1 to n do begin
            now:=gcd(now,a[i]); if now=1 then break;
            k3:=now; k1:=0;
            for j:=1 to m do
                if k3 mod b[j]=0 then
                    while k3 mod b[j]=0 do begin
                        inc(k1); k3:=k3 div b[j];
                    end;
            k2:=find(now); c[i]:=k2-k1*2;
        end;
        pre:=n+1; num:=0;
        for i:=n downto 1 do
            if c[i]<num then begin
                tot:=tot-i*(c[i]-num); num:=c[i];
            end;
        writeln(tot);
    end.