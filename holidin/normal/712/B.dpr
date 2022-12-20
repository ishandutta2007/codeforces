var m: array[#0..#225]of longint;
    i, j, k, n, x, y: longint; s:string;

begin
   {assign(input, 'input.txt'); reset(input);
   assign(output, 'output.txt'); rewrite(output); }
   readln(s);
   for i := 1 to length(s) do
   inc(m[s[i]]);
   if (m['L'] + m['R']) mod 2 <> (m['U'] + m['D']) mod 2 then begin write(-1); halt(0); end;
   if (m['L'] + m['R']) mod 2 = 0 then write(abs(m['L'] - m['R']) div 2 + abs((m['U'] - m['D']) div 2))
   else write(1 + abs(m['L'] - m['R']) div 2 + abs(m['U'] - m['D']) div 2);
end.