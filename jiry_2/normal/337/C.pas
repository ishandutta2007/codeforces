program exam;
	const
		modd=1000000009;
	var
		i,j,n,m,k,tot,num,ans:int64;
	function quick(k1,k2:int64):int64;
		begin
			if k2=1 then exit(k1);
			if k2 mod 2=1 then exit(sqr(quick(k1,k2 div 2)) mod modd*k1 mod modd);
			exit(sqr(quick(k1,k2 div 2)) mod modd);
		end;
	begin
		{assign(input,'exam.in'); reset(input);
		assign(output,'exam.out'); rewrite(output);}
		readln(n,m,k);
		tot:=n div k;
		if n-tot>=m then
			writeln(m)
		else begin
			tot:=m-(n-tot);
			ans:=((quick(2,tot)+modd-1) mod modd)*k mod modd*2 mod modd;
			ans:=(ans+m-tot*k) mod modd;
			writeln(ans);
		end;
		{close(input); close(output);}
	end.