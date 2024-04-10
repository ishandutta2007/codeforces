program Project1; {$Q+ $R+}
const mod1 = 1000000;

var i, j, k, n: longint;  s, s1: string; c, c1: char;
    m: array['a'..'z']of char;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    readln(n);
    readln(s);
    c := #0;
    c1 := #1;
    k := 1;
    for i := 1 to n do
    begin
        if (s[i] = 'R') and (c = 'L') then  begin inc(k); c := #0; c1 := #1; end;
        if (s[i] = 'L') and (c = 'R') then   begin inc(k); c := #0; c1 := #1; end;
        if (s[i] = 'U') and (c1 = 'D') then  begin inc(k); c := #0; c1 := #1; end;
        if (s[i] = 'D') and (c1 = 'U') then  begin inc(k); c := #0; c1 := #1; end;
        if (s[i] = 'R') or (s[i] = 'L') then
            c := s[i]
        else
            c1 := s[i];
    end;
    write(k);
end.