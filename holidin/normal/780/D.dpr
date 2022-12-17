const mod1 = 1024*1024;
div1 = 37;

var    s: string;
i, j, k, n, a, b, top, top1: longint; c, c1, c2: char;
     su: array['A'..'Z', 'A'..'Z', 'A'..'Z']of integer;
     sa: array['A'..'Z', 'A'..'Z']of integer;
     si: array['A'..'Z', 'A'..'Z']of integer;
     d: array[1..1000]of record i, j: integer; end;
     F: array[1..1000]of integer;
     he: array[0..mod1*2]of record s: string[20]; i: longint; end;
     m: array[0..1000]of record s: string; i: longint; c: string; c1: char; end;
     p: array['A'..'Z', 0..2]of boolean;
     Lp, lp1: array[1..1000]of record i: integer; c: char; end;
     top3: longint;

function hesh(s: string): longint;
var i: longint; j: int64;
begin
    j := 0;
    for i := 1 to length(s) do
    j := (j * div1 + ord(s[i]) - ord('A') + 1) mod mod1;
    while (he[j].s <> '') and (he[j].s <> s) do inc(j);
    hesh := j;
end;

procedure pruv(i1, j: integer; b: boolean);
var i: longint; b5, b6, b7: boolean;  pp: integer;  c4: char;
begin
    if j = 0 then
    begin
        if top1 <> -1 then
        lp1 := lp;
        top3 :=i1 - 1;
        exit;
    end;
    i := d[j].i;
    pp := f[m[i].i];
    if su[c, c1, m[i].s[3]] > 1 then
    begin
        if (not p[m[i].s[3], 0]) and (f[m[i].i] <> 2) then
        begin
            p[m[i].s[3], 0] := true;
            p[m[i].s[3], 1] := true;
            p[m[i].s[3], 2] := true;
            f[m[i].i] := 1;
            lp[i1].i := i;
            lp[i1].c := m[i].s[3];
            pruv(i1 + 1, d[j].j, b);
            p[m[i].s[3], 0] := false;
            p[m[i].s[3], 1] := false;
            p[m[i].s[3], 2] := false;
            f[m[i].i] := pp;
        end;
        if ((not p[m[i].s[3], 2]) or (m[i].s[3] = m[i].c[1])) and (not p[m[i].c[1], 1]) and (f[m[i].i] <> 1)then
        begin
            p[m[i].c[1], 0] := true;
            p[m[i].c[1], 1] := true;
            b5 := p[m[i].s[3], 0];
            p[m[i].s[3], 0] := true;
            f[m[i].i] := 2;
            lp[i1].i := i;
            lp[i1].c := m[i].c[1];
            pruv(i1 + 1, d[j].j, b);
            p[m[i].c[1], 0] := false;
            p[m[i].c[1], 1] := false;
            p[m[i].s[3], 0] := b5;
            f[m[i].i] := pp;
        end;
    end else
    if (not p[m[i].s[3], 0]) {and (not p[m[i].s[3], 1])} and (f[m[i].i] <> 2) then
        begin
            p[m[i].s[3], 0] := true;
            p[m[i].s[3], 1] := true;
            p[m[i].s[3], 2] := true;
            lp[i1].i := i;
            lp[i1].c := m[i].s[3];
            f[m[i].i] := 1;
            pruv(i1 + 1, d[j].j, b);
            p[m[i].s[3], 0] := false;
            p[m[i].s[3], 1] := false;
            p[m[i].s[3], 2] := false;
            f[m[i].i] := pp;
        end else
        if ((not p[m[i].s[3], 2]) or (m[i].s[3] = m[i].c[1])) and (not p[m[i].c[1], 1]) and (f[m[i].i] <> 1) then
        begin
            p[m[i].c[1], 0] := true;
            p[m[i].c[1], 1] := true;
            b5 := p[m[i].s[3], 0];
            p[m[i].s[3], 0] := true;
            lp[i1].i := i;
            f[m[i].i] := 2;
            lp[i1].c := m[i].c[1];
            pruv(i1 + 1, d[j].j, b);
            p[m[i].c[1], 0] := false;
            p[m[i].c[1], 1] := false;
            p[m[i].s[3], 0] := b5;
            f[m[i].i] := pp;
        end;
end;


begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);  }
    readln(n);
    for i := 1 to n do
    begin
        readln(s);
        m[i].s := copy(s, 1, pos(' ', s) - 1);
        j := hesh(m[i].s);
        if he[j].s = '' then
        begin
            inc(top1);
            he[j].s := m[i].s;
            he[j].i := top1;
            m[i].i := top1;
        end else
         m[i].i := he[j].i;
        inc(sa[m[i].s[1], m[i].s[2]]);
        inc(su[m[i].s[1], m[i].s[2], m[i].s[3]]);
        inc(top);
        d[top].i := i;
        if si[m[i].s[1], m[i].s[2]] = 0 then
        si[s[1], s[2]] := top
        else
        begin
            d[top].j := si[s[1], s[2]];
            si[s[1], s[2]] := top;
        end;
        m[i].c := copy(s, pos(' ', s) + 1, 1);
        inc(su[m[i].s[1], m[i].s[2], m[i].c[1]]);
    end;
    {for c := 'A' to 'Z' do
    for c1 := 'A' to 'Z' do
    for c2 := 'A' to 'Z' do
    if su[c, c1, c2] > 1 then
    for i := 1 to n do
    if m[i].s = c + c1 + c2 then
    b[i] := true;  }
    for c := 'A' to 'Z' do
    for c1 := 'A' to 'Z' do
    if sa[c, c1] > 26 then
    begin
       writeln('NO');
       halt(0);
    end else
    begin
        for c2 := 'A' to 'Z' do
        for i := 0 to 1 do
        p[c2, i] := false;
        for i := 1 to 1000 do
        f[i] := 0;
        top3 := -1;
        pruv(1, si[c, c1], true);
        if top3 = -1 then
        begin
            writeln('NO');  halt(0); end;
            for i := 1 to top3 do
            m[lp1[i].i].c1 := lp1[i].c;
    end;
    writeln('YES');
    for i := 1 to n do
    writeln(m[i].s[1], m[i].s[2], m[i].c1);
end.