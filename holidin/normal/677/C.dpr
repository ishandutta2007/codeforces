program q;
var k,n,o,h,p:int64; i,j:longint;  m:array[0..63]of longint;
c:char;
begin
  {assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  }for i:=0 to 63 do
  for j:=0 to 63 do
  inc(m[i and j]);
  k:=1;
  while (not eof) and (not eoln) do
  begin
     read(c);
     if (c>='0') and (c<='9')
     then k:=k*m[(ord(c)-ord('0'))]
     else if (c>='A') and (c<='Z')
          then k:=k*m[(ord(c)-ord('A')+10)]
          else if (c>='a') and (c<='z')
               then k:=k*m[(ord(c)-ord('a')+36)]
               else if c='-'
                    then k:=k*m[62]
                    else k:=k*m[63];
     k:=k mod 1000000007;
  end;
  write(k)
end.