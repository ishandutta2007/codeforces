program q;
const mx = 1000000001;
var n, x0, y0, x, y, i: longint;
    yn, yv, xp, xl, ylv, yvv, yln, yvn: longint;
    cn, cv, cl, cp, clv, cvv, cln, cvn, c: char;

begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);  }
    read(n);
    readln(x0, y0); yn := -mx; yv := mx; xp := mx; xl := -mx;
    cn := 'B'; cv := 'B'; cp := 'B'; cl := 'B';
    clv := 'R'; cln := 'R'; cvv := 'R'; cvn := 'R';
    ylv := mx;
    yln := -mx;
    yvv := mx;
    yvn := -mx;
    for i := 1 to n do
    begin
        read(c);
        readln(x, y);
        if x = x0 then
            if y < y0 then
                if yn < y then
                begin
                    cn := c;
                    yn := y
                end else
            else
                if yv > y then
                begin
                    cv := c;
                    yv := y;
                end;
        if y = y0 then
            if x < x0 then
                if xl < x then
                begin
                    cl := c;
                    xl := x
                end else
            else
                if xp > x then
                begin
                    cp := c;
                    xp := x;
                end;
        if abs(x - x0) = abs(y - y0) then
            if x < x0 then
                if y > y0 then
                    if ylv > y then
                    begin
                        clv := c;
                        ylv := y;
                    end else
                else
                    if yln < y then
                    begin
                        cln := c;
                        yln := y;
                    end else
            else
                if y > y0 then
                    if yvv > y then
                    begin
                        cvv := c;
                        yvv := y;
                    end else
                else
                    if yvn < y then
                    begin
                        cvn := c;
                        yvn := y;
                    end;
    end;
    if (cp = 'B') and (cl = 'B') and (cv = 'B') and (cn = 'B') and (clv = 'R') and (cvv = 'R')
    and (cvn = 'R') and (cln = 'R') then
    write('NO') else write('YES');
end.