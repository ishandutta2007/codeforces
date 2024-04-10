program Project1; {$Q+ $R+}


type mas=array[0..30]of longint;

var
  i, j, n, o, max, x, a: longint;   k: int64;
  m: array[0..100000]of int64;


begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    read(n, x);
    for i := 1 to n do
    begin
        read(j);
        if j xor x <= 100000 then k := k + m[j xor x];
        inc(m[j]);
    end;
    write(k);
end.