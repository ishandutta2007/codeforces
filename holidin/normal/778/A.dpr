type y = array[0..31]of integer;

var D: array[0..200000]of boolean;
    k: array[0..200000]of longint;
    max, i, j, n, x, l, r, o: longint;   s, s1, s2: string;


begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);}
    readln(s);
    readln(s1);
    for i := 1 to length(s) do
    read(k[i]);
    l := 0;
    r := length(s) - length(s1) + 1;
    while l <> r - 1 do
    begin
        s2 := '';
        x := (l + r) div 2;
        for o := 1 to length(s) do
        d[o] := true;
        for o := 1 to x do
        d[k[o]] := false;
        for o := 1 to length(s) do
        if d[o] then s2 := s2 + s[o];
        j := 1;
        for i := 1 to length(s2) do
        if j <= length(s1) then if s2[i]  = s1[j] then inc(j);
        if j <= length(s1) then
            r := x
        else
            l := x;
    end;
    write(l);
end.