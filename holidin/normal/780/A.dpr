program q;
var i, j, k, n, p: longint;
    var m: array[0..10000]of record i, j: longint; end;
    b: array[1..100000]of longint;

{procedure sort(var m: mas; first, last: longint);
var f, l: longint; mid: longint;
begin
    f := first;
    l := last;
    mid := m[(f + l) div 2];
    repeat
        while m[f] > mid do inc(f);
        while m[l] < mid do dec(l);
        if f <= l then
        begin
            m[0] := m[f];
            m[f] := m[l];
            m[l] := m[0];
            inc(f);
            dec(l);
        end;
    until f > l;
    if f < last then sort(f, last);
    if first < l then sort(first, l);
end;
     }
begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);   }
    read(n);
    k := 0;
    p := 0;
    for i := 1 to 2*n do
    begin
        read(j);
        inc(b[j]);
        if b[j] = 1 then inc(k) else dec(k);
        if p < k then p := k;
    end;
    write(p);
end.