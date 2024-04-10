program Project1; {$Q+ $R+}


type mas=array[0..30]of longint;

var
  a, m: array[0..200]of int64;
  i: longint;
  j, t, n, max: int64;

function nod(a, b: int64): int64;
begin
    if b = 0 then nod := a else nod := nod(b, a mod b);
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);  }
    read(n);
    for i := 1 to n do
    read(a[i]);
    t := 1;
    for i := 1 to n do
    if m[i] = 0 then
    begin
        j :=a[i];
        max := 1;
        m[j] := 1;
        while (max < 111) and (j <> i) do
        begin
            inc(max);
            m[j] := 1;
            j := a[j];
        end;
        if max = 111 then begin write(-1); halt(0); end;
        if max mod 2 = 0 then max := max div 2;
        if t >= max then t := (t * max) div nod(t, max) else t := (t * max) div nod(max, t);
    end;
    write(t);
end.