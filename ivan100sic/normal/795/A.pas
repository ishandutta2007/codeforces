var
	n, c1, c2 : Int64;
	s : AnsiString;

	j, k, a, b, c, d, e, f, val, opt : Int64;
	i, g : Longint;

begin
	Readln(n, c1, c2);
	Readln(s);

	a := 0;
	b := 0;

	for i := 1 to n do begin
		if s[i] = '1'
		then
			inc(a)
		else
			inc(b);
	end;

	opt := -1;

	for g := 1 to a do begin
		c := n div g; // c je manja velicina grupe
		e := n mod g; // e je broj nabudzenih grupa

		d := g - e; // d je broj manjih grupa

		val := d * (c1 + c2 * (c - 1) * (c - 1));
		val := val + e * (c1 + c2 * c * c);

		if (opt = -1) or (val < opt) then
			opt := val;
	end;

	Writeln(opt);
end.