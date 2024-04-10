var
s:string;
i,j:integer;

black,white:integer;
procedure choseb(var c:char);
 begin
 if c=('q') then inc(black,9);
 if c=('r') then inc(black,5);
 if (c=('b')) or (c=('n')) then inc(black,3);
 if c=('p') then inc(black);
 end;


procedure chosew(var c:char);
 begin
  if c=('Q') then inc(white,9);
  if c=('R') then inc(white,5);
  if (c=('B')) or (c=('N')) then inc(white,3);
  if c=('P') then inc(white);
 end;


begin

 for i:=1 to 8 do
 for j:=1 to 8 do
  begin
   if j=1 then readln(s);
   if ord(s[j])<>46 then begin

    if ord(s[j])<93 then chosew(s[j]);
	if ord(s[j])>=98 then choseb(s[j]);
   end;
  end;
  if white=black then writeln('Draw') else
  if white>black then writeln('White') else
  writeln('Black');

  end.