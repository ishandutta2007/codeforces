
const mod1 = 1024*1024;
    div1 = 151235;

var i, j, k, n, p, top, a, b, o: longint;
    s, m: array[0..60]of longint; c, c1: char;



begin
   { assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    readln(n, k);
    for i := 1 to n - k + 1 do
    begin
        read(c);
        if c = 'N' then
        begin read(c1); read(c1)end  else begin read(c1); read(c1); read(c1); end;
        if c = 'Y' then
        p := i;
        if c= 'Y' then m[i] := 1;
    end;
    if p = 0 then
    begin
        for i := 1 to n do
        write('T ');
        halt(0);
    end;
    for i := p to p + k - 1 do
    begin
        inc(top);
        s[i] := top;
    end;
    for i := p + 1 to n - k + 1 do
    if m[i] = 1 then
    begin
        inc(top);
        s[i + k - 1] := top;
    end else
       s[i + k - 1] := s[i];
    for i := p - 1 downto 1 do
    if m[i] = 1 then
    begin
        inc(top);
        s[i] := top;
    end else
        s[i] := s[i + k - 1];
    for i := 1 to n do
    write(chr(ord('A') + s[i] div 20), chr(ord('a') + s[i] mod 20), ' ');
end.