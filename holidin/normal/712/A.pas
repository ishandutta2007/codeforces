var a, b: array[1..100000]of int64;
    i, j, k, n: longint;

begin
   {assign(input, 'input.txt'); reset(input);
   assign(output, 'output.txt'); rewrite(output); }
   read(n);
   for i := 1 to n do
   read(b[i]);
   a[n] := b[n];
   for i := n - 1 downto 1 do
   a[i] := b[i] + b[i + 1];
   for i := 1 to n do
   write(a[i], ' ');
end.