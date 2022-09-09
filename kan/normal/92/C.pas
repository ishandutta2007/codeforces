{$Q+,S+,R+,I+,O-}
{$mode delphi}

var k,cur:array['a'..'z'] of longint;
    p:array['a'..'z',1..10000] of longint;
    curp:longint;
    s1,s2:string;
    n1,n2,i,ans:longint;
    ch:char;

function find(ch:char):longint;
var l,r,m:longint;
begin
l:=cur[ch];
r:=k[ch]+1;
while r-l>1 do begin
      m:=(l+r) div 2;
      if p[ch,m]>curp then r:=m
		      else l:=m;
end;
if p[ch,l]<curp then exit(l+1)
		else exit(l);
end;

begin
// assign(input,'input.txt');
// reset(input);
readln(s1);
readln(s2);
n1:=length(s1);
n2:=length(s2);
// assign(output,'output.txt');
// rewrite(output);
for ch:='a' to 'z' do k[ch]:=0;
for i:=1 to n1 do begin
    inc(k[s1[i]]);
    p[s1[i],k[s1[i]]]:=i;
end;
// writeln('prp');
// for ch:='a' to 'z' do writeln(ch,' ',k[ch]);
// writeln(s2);
for i:=1 to n2 do if k[s2[i]]=0 then begin
    writeln(-1);
//     close(output);
    halt;
end;
ans:=1;
for ch:='a' to 'z' do cur[ch]:=1;
for i:=1 to n2 do begin
    cur[s2[i]]:=find(s2[i]);
//     writeln(cur[s2[i]]);
    if cur[s2[i]]>k[s2[i]] then begin
	for ch:='a' to 'z' do cur[ch]:=1;
// 	writeln('incans');
	inc(ans);
    end;
    curp:=p[s2[i],cur[s2[i]]]+1;
end;
writeln(ans);
// close(output);
end.