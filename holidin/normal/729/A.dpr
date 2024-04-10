program q;  {$Q+ $R+}
var i, a, d, n, j: longint; c: char;  s: string;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);  }
    readln(n);
    readln(s);
    i := 1;
    while i < n - 1 do
    begin
        if (s[i] = 'o') and (s[i + 1] = 'g') and (s[i + 2] = 'o')
        then
        begin
            i := i + 3;
            while (i < n) and (s[i] = 'g') and (s[i + 1]='o') do i := i + 2;
            write('***');
        end
        else begin write(s[i]); inc(i); end;
    end;
    for j := i to n do
    write(s[j]);
end.