program cfa;
uses strutils;
const
     fre:string='lala.';
     rai:string='miao.';
var
   n,i:integer;
   f,r:boolean;
   s:string;
begin
     readln(n);
     for i:=1 to n do
         begin
              readln(s);
              if (length(s)<5) then
                  begin
                        writeln('OMG>.< I don''t know!');
                        continue;
                  end;
              f:=rpos(fre,s)=length(s)-4;
              r:=pos(rai,s)=1;
              if (f) and not (r) then writeln('Freda''s')
              else if (r) and not (f) then writeln('Rainbow''s')
              else writeln('OMG>.< I don''t know!');
         end;
end.