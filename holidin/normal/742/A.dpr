program Project1; {$Q+ $R+}


type mas=array[0..30]of longint;

var
  i, j, k, n, o, max: longint;
  m: array[0..10]of longint;


begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    read(n);
    if n = 0  then begin write(1); halt(0); end;
    dec(n);
    n := n mod 4;
    m[0] := 8;
    for i := 1 to 5 do
    m[i] := (m[i - 1] * 8) mod 10;
    write(m[n]);
end.