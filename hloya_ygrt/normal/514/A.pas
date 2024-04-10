var
x:string;
i,b:integer;
 begin
   readln(x);
   i:=1;
   if x[1]<>('9') then 
   if (ord(x[i])>=53) then begin b:=ord(x[i])-48; b:=abs(9-b); b:=b+48; x[i]:=chr(b); end;

  if length(x)>1 then
   for i:=2 to length(x) do
        begin
   	
              if (ord(x[i])>=53) then begin b:=ord(x[i])-48; b:=abs(9-b); b:=b+48; x[i]:=chr(b); end;
        
	end;
  writeln(x);
 end.