var
	a:array[0..11] of string;
	n,m,req,res,cnt,i,j:longint;
begin
	readln(m,n,req);
	for i:=1 to m do readln(a[i]);
	for j:=1 to n do begin
		cnt:=0;
		for i:=1 to m do
			if a[i][j]='Y' then inc(cnt);
		if cnt>=req then inc(res);
	end;
	writeln(res);
end.
{kitten}