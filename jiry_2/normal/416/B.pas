program p02;
	var
		x:array[1..50000,1..5] of longint;
		f:array[1..50000] of longint;
		i,j,n,m,now:longint;
	begin
		readln(n,m);
		for i:=1 to n do
			for j:=1 to m do
				read(x[i,j]);
		fillchar(f,sizeof(f),0);
		for i:=1 to n do begin
			now:=0;
			for j:=1 to m do begin
				if now>f[j] then f[j]:=now;
				f[j]:=f[j]+x[i,j];
				now:=f[j];
			end;
			write(now,' ');
		end;
		writeln;
	end.