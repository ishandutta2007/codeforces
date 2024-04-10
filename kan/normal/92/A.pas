{$Q+,S+,R+,I+,O-}
{$mode delphi}

var n,m,cur:longint;

begin
// assign(input,'input.txt');
// reset(input);
readln(n,m);
cur:=1;
while m>0 do begin
      if m-cur<0 then break;
      m:=m-cur;
      cur:=cur+1;
      if cur>n then cur:=1;
end;
// assign(output,'output.txt');
// rewrite(output);
writeln(m);
// close(output);
end.