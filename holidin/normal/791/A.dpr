type y = array[0..31]of integer;
const mod1 = 1024*1024;
    div1 = 33;

var i, a, b: longint;

begin
   { assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);    }
    read(a, b);
    i := 0;
    while a <= b do
    begin
        inc(i);
        a := a * 3;
        b := b * 2;
    end;
    write(i);
end.