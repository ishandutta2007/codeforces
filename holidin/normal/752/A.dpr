program Project1; {$Q+ $R+}
const mod1 = 1000000;

var i, j, k, n, m: longint;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    readln(n, m, k);
    dec(k);
    write(1 + (k div (2*m)), ' ');
    k := k mod (2*m);
    write((k div 2) + 1, ' ');
    if k mod 2  = 0 then writeln('L') else writeln('R');
end.