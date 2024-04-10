var
	k1,k2,k3:int64;
	i,j,n:longint;
	ch1,ch2:char;
begin
	readln(n); k1:=-2000000001; k2:=2000000001;
	for i:=1 to n do begin
		read(ch1); read(ch2); read(k3);
		if (ch1='>') then begin
			read(ch1); read(ch1);
			if ch1='Y' then begin
				if (ch2='=') then k3:=k3-1; if k3>k1 then k1:=k3;
			end else begin
				if (ch2<>'=') then k3:=k3+1; if k3<k2 then k2:=k3;
			end;
		end else begin
			read(ch1); read(ch1);
			if (ch1='Y') then begin
				if (ch2='=') then k3:=k3+1; if k3<k2 then k2:=k3;
			end else begin
				if (ch2<>'=') then k3:=k3-1; if k3>k1 then k1:=k3;
			end;
		end;
		readln;
	end;
	if (k2-k1<2) then writeln('Impossible') else writeln(k1+1);
end.