program q;
var a:array[0..101,0..101]of char;
 i,j,n,m,k,f1,f2:longint;
begin
    {assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);  }
    readln(n,m);
    for i:=1 to n do
    begin
    for j:=1 to m do
    read(a[i,j]);
    readln;
    end;
    k:=n;
    while a[k-1,1]='*' do
    dec(k);
    f1:=0;
    f2:=0;
    for j:=2 to m do
    begin
        i:=0;
        if a[k,j]='*'
        then while a[k+i-1,j]='*' do
             dec(i)
        else while a[k+i,j]='.' do
             inc(i);
        if f1>i
        then f1:=i;
        if f2<i
        then f2:=i;
        k:=k+i
    end;
    write(abs(f1),' ',f2)
end.