{$Q+,S+,R+,I+,O-}
{$mode delphi}

var s:string;
    i,n,tmp,ans:longint;

begin
// assign(input,'input.txt');
// reset(input);
readln(s);
// assign(output,'output.txt');
// rewrite(output);
n:=length(s);
tmp:=0;
ans:=0;
for i:=n downto 2 do begin
    if (s[i]='1') then begin
	if tmp=1 then inc(ans,1)
		  else begin
		      inc(ans,2);
		      tmp:=1;
		  end;
    end else begin
	if tmp=1 then inc(ans,2)
		  else begin
			  inc(ans,1);
			  tmp:=0;
		  end;
    end;
end;
if tmp=1 then inc(ans);
writeln(ans);    
// close(output);
end.