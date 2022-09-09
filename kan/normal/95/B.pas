{$Q+,S+,R+,I+,O-}
{$mode delphi}

var s,ans:string;
	n,pk,i:longint;

procedure outwrite;
begin
for i:=1 to n do write(ans[i]);
//close(output);
halt;
end;

procedure go(curp,curk4,curk7:longint; big:boolean);
begin
if curp>n then outwrite;
//writeln(curp,' ',curk4,' ',curk7,' ',big);
if ((big)or(s[curp]<='4'))and(curk4<pk) then begin
	ans[curp]:='4';
//	writeln('try4');
	if s[curp]<'4' then go(curp+1,curk4+1,curk7,true)
			else go(curp+1,curk4+1,curk7,big);
end;
//writeln('endtry');
if ((big)or(s[curp]<='7'))and(curk7<pk) then begin
	ans[curp]:='7';
//	writeln('try7');
	if s[curp]<'7' then go(curp+1,curk4,curk7+1,true)
			else go(curp+1,curk4,curk7+1,big);
end;
end;

begin
//assign(input,'input.txt');
//reset(input);
readln(s);
//assign(output,'output.txt');
//rewrite(output);
n:=length(s);
if n mod 2=1 then begin
	for i:=1 to n div 2 +1 do write('4');
	for i:=1 to n div 2 +1 do write('7');
//	close(output);
	halt;
end;
//writeln(n);
ans:=s;
pk:=n div 2;
go(1,0,0,false);
//writeln('endg');
{big:=false;
k4:=0;
for i:=1 to n do begin
	if big then begin
		if k4<n div 2 then begin
			inc(k4);
			ans[i]:='4';
		end else ans[i]:='7';
	end else begin
		if s[i]<'4' then begin
			if k4<n div 2 then begin
				inc(k4);
				ans[i]:='4';
			end else ans[i]:='7';
			big:=true;
		end else if s[i]='4' then begin
			if (k4<n div 2)and(s[i+1]<='7')}
for i:=1 to n div 2 +1 do write('4');
for i:=1 to n div 2 +1 do write('7');
//close(output);
end.