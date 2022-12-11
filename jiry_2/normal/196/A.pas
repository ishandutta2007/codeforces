program p01;
    var
        x,y:array[0..200000] of longint;
        i,j,n:longint;
        s:ansistring;
    procedure sort(first,en:longint);
        var
            i,j,k:longint;
        begin
            i:=first; j:=en; y[0]:=y[first+random(en-first+1)];
            while i<=j do begin
                while (i<=j) and ((x[y[j]]<x[y[0]]) or ((x[y[j]]=x[y[0]]) and (y[j]>y[0]))) do dec(j);
                while (i<=j) and ((x[y[i]]>x[y[0]]) or ((x[y[i]]=x[y[0]]) and (y[i]<y[0]))) do inc(i);
                if i<=j then begin
                    k:=y[i]; y[i]:=y[j]; y[j]:=k; inc(i); dec(j);
                end;
            end;
            if j>first then sort(first,j);
            if i<en then sort(i,en);
        end;
    begin
        readln(s);
        randomize;
        n:=length(s);
        for i:=1 to n do x[i]:=ord(s[i]);
        for i:=1 to n do y[i]:=i;
        sort(1,n);
        j:=y[1]; write(s[j]);
        for i:=2 to n do
            if y[i]>j then begin
                j:=y[i]; write(s[j]);
            end;
    end.