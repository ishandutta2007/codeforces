{$Q+,S+,R+,I+,O-}
{$mode delphi}

var r,g,b,kr,kg,kb,tr,tg,tb,t:longint;

begin
//assign(input,'input.txt');
//reset(input);
readln(r,g,b);
kr:=r div 2;
if kr*2<r then kr:=kr+1;
tr:=(kr-1)*3;
kg:=g div 2;
if kg*2<g then kg:=kg+1;
tg:=(kg-1)*3+1;
kb:=b div 2;
if kb*2<b then kb:=kb+1;
tb:=(kb-1)*3+2;
t:=tr;
if tb>t then t:=tb;
if tg>t then t:=tg;
//assign(output,'output.txt');
//rewrite(output);
writeln(t+30);
//close(output);
end.