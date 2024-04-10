{$Q+,S+,R+,I+,O-}
{$mode delphi}

var p:array[1..100,1..100] of char;
    d:array[1..100,1..100] of longint;
    i,j,i2,n,m:longint;

begin
//assign(input,'input.txt');
//reset(input);
readln(n,m);
for i:=1 to n do begin	
    for j:=1 to m do begin
	read(p[i,j]);
    end;
    readln;
end;
for i:=1 to n do begin
    for j:=1 to m do begin
	for i2:=1 to n do if (i<>i2)and(p[i,j]=p[i2,j]) then d[i,j]:=1;
	for i2:=1 to m do if (j<>i2)and(p[i,j]=p[i,i2]) then d[i,j]:=1;
    end;
end;
//assign(output,'output.txt');
//rewrite(output);
for i:=1 to n do begin
    for j:=1 to m do if d[i,j]=0 then write(p[i,j]);
end;
//close(output);
end.