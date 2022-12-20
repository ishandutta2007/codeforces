program q;  {$Q+ $R+}
var i, a, d, n: longint; c: char;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    readln(n);
    for i := 1 to n do
    begin
        read(c);
        if c = 'A' then inc(a) else inc(d);
    end;
    if a = d then write('Friendship') else
    if a > d then write('Anton') else write('Danik');
end.