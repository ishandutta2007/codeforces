program q;
var  n,m,k,i,j,a,b,a1,b1,l:longint;
begin
   { assign(input,'input.txt'); reset(input);
    assign(output,'output.txt'); rewrite(output);
    }readln(n,m,k);
   read(a,b);
    if b>a
    then begin a1:=a; a:=b; b:=a1 end;
    a1:=(a-1) div (m*k)+1;
    b1:=(b-1) div (m*k)+1;
    if a1-b1>b1+n-a1
    then begin l:=a1; a1:=b1+n; b1:=l; end;
    i:=(a1-b1)*15;
    a:=(a-1) mod (m*k);
    b:=(b-1) mod (m*k);
    if i=0
    then begin l:=(b div k)*k; a:=a-l; b:=b-l end;
    a:=a div k;
    if 10+a> a*5
    then i:=i+a*5
    else i:=i+10+a;
    b:=b div k;
    if 10+b>b*5
    then i:=i+b*5
    else i:=i+10+b;
    write(i);
end.