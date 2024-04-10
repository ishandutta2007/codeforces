type y = array[0..31]of integer;
const mod1 = 1024*1024;
    div1 = 33;

var D: array[0..mod1*2]of record s: string[10]; num: integer; end;
    p: array[0..5000]of string;
    u: array[0..5000]of record a, b: integer; t: byte; end;c: char;

    max, i, j, n, x, l, r, o, k: longint;   s, s1, s2: string;


function or1(a, b: char): byte;
begin
    if (a = '1') or (b = '1') then or1 := 1 else or1 := 0;
end;

function xor1(a, b: char): byte;
begin
    if a = b then xor1 := 0 else xor1 := 1;
end;

function and1(a, b: char): byte;
begin
    if (a = '1') and (b = '1') then and1 := 1 else and1 := 0;
end;

function hesh(s: string): longint;
var i, j: longint;
begin
    i := 0;
    for j := 1 to length(s) do
    i := (i * div1  + ord(s[j]) - ord('a') + mod1) mod mod1;
    while (d[i].s <> '') and (d[i].s <> s) do
    inc(i);
    hesh := i;
end;

procedure procmin(o: integer);
var i, j0, j1: longint;
begin
    j0 := 0;
    p[0][o] := '0';
    for j := 1 to n do
    begin
    case u[j].t of
    0: p[j][o] := chr(ord('0') + or1(p[u[j].a][o], p[u[j].b][o]));
    1: p[j][o] := chr(ord('0') + and1(p[u[j].a][o], p[u[j].b][o]));
    2: p[j][o] := chr(ord('0') + xor1(p[u[j].a][o], p[u[j].b][o]));
    end;
       if p[j][o] = '1' then inc(j0);
    end;
    j1 := 0;
    p[0][o] := '1';
    for j := 1 to n do
    begin
    case u[j].t of
    0: p[j][o] := chr(ord('0') + or1(p[u[j].a][o], p[u[j].b][o]));
    1: p[j][o] := chr(ord('0') + and1(p[u[j].a][o], p[u[j].b][o]));
    2: p[j][o] := chr(ord('0') + xor1(p[u[j].a][o], p[u[j].b][o]));
    end;
       if p[j][o] = '1' then inc(j1);
    end;
    if j0 <= j1 then p[0][o] := '0' else p[0][o] := '1';
end;

procedure procmax(o: integer);
var i, j0, j1: longint;
begin
    j0 := 0;
    p[0][o] := '0';
    for j := 1 to n do
    begin
    case u[j].t of
    0: p[j][o] := chr(ord('0') + or1(p[u[j].a][o], p[u[j].b][o]));
    1: p[j][o] := chr(ord('0') + and1(p[u[j].a][o], p[u[j].b][o]));
    2: p[j][o] := chr(ord('0') + xor1(p[u[j].a][o], p[u[j].b][o]));
    end;
       if p[j][o] = '1' then inc(j0);
    end;
    j1 := 0;
    p[0][o] := '1';
    for j := 1 to n do
    begin
    case u[j].t of
    0: p[j][o] := chr(ord('0') + or1(p[u[j].a][o], p[u[j].b][o]));
    1: p[j][o] := chr(ord('0') + and1(p[u[j].a][o], p[u[j].b][o]));
    2: p[j][o] := chr(ord('0') + xor1(p[u[j].a][o], p[u[j].b][o]));
    end;
       if p[j][o] = '1' then inc(j1);
    end;
    if j0 >= j1 then p[0][o] := '0' else p[0][o] := '1';
end;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output); }
    readln(n, k);
    for i := 1 to n do
    begin
        s := '';
        read(c);
        while c <> ' ' do
        begin
            s := s + c;
            read(c);
        end;
        read(c); read(c); read(c); read(c);
        if (c = '0') or (c = '1') then
        begin
            readln(s1);
            p[i] := c + s1;
            u[i].t := 3;
        end else
        begin
            s1 := '';
            while c <> ' ' do
            begin
                s1 := s1 + c;
                read(c);
            end;
            u[i].a := d[hesh(s1)].num;
            read(c);
            s1 := '';
            while c <> ' ' do
            begin
                s1 := s1 + c;
                read(c);
            end;
            if s1 = 'OR' then u[i].t := 0;
            if s1 = 'AND' then u[i].t := 1;
            if s1 = 'XOR' then u[i].t := 2;
            readln(s1);
            u[i].b := d[hesh(s1)].num;
            for j := 1 to k do
            p[i] := p[i] + '1';
        end;
        j := hesh(s);
        d[j].s := s;
        d[j].num := i;
    end;
    for i := 1 to k do
    p[0] := p[0] + '1';
    for i := 1 to k do
    procmin(i);
    writeln(p[0]);
    for i := 1 to k do
    procmax(i);
    writeln(p[0]);
end.