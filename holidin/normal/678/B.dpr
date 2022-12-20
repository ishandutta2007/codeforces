program q;
var n,k,i,j,y,o:longint;
begin
 { assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  }read(y);
  if (y mod 400=0) or ((y mod 4=0) and (y mod 100<>0))
  then i:=4
  else i:=1;
  j:=y;
  k:=y mod 7;
  repeat
    if (j mod 400=0) or ((j mod 4=0) and (j mod 100<>0))
    then begin k:=k+2;  end
    else begin k:=k+1;  end;

    inc(j);
    if (j mod 400=0) or ((j mod 4=0) and (j mod 100<>0))
  then o:=4
  else o:=1;
  until (k mod 7=y mod 7) and (o=i);
  write(j)
end.