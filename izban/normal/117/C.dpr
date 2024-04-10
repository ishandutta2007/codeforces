{$APPTYPE CONSOLE}
uses math;
var
  i,j,n,k:integer;
  a:array[0..5001,0..5001]of char;
  h:array[1..5000]of integer;
  g,v,g0,v0:array[0..5001]of boolean;
  b:array[1..3]of integer;
function dfs(x,v:integer):boolean;
var i:integer;
begin
  result:=false;
  b[x]:=v;
  if (x=3)and(a[v,b[1]]='1') then begin
    for i:=1 to 3 do write(b[i],' ');
    result:=true;
    halt(0);
  end;
  for i:=1 to n do if (a[v,i]='1')and(i<>v) then begin
    if dfs(x+1,i) then begin
      result:=true;
      writeln(v); exit;
    end;
  end;
end;
begin
{$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
{$ENDIF}
  readln(n);
  for i:=1 to n do begin
    for j:=1 to n do begin
      read(a[i,j]);
      inc(h[i],ord(a[i,j]='1'));
    end;
    readln;
  end;
  for i:=1 to n do
    for j:=1 to n do
      if h[i]=h[j] then begin
        for k:=1 to n do
          if (a[i,j]='1')and(a[j,k]='1')and(a[k,i]='1') then begin
            write(i,' ',j,' ',k);
            halt(0);
          end else
          if (a[j,i]='1')and(a[i,k]='1')and(a[k,j]='1') then begin
            write(j,' ',i,' ',k);
            halt(0);
          end;
      end;
{  for i:=1 to n do begin
    for j:=1 to n do begin
      read(a[i,j]);
      if a[i,j]='1' then begin
        g[i]:=true;
        h[j]:=true;
      end else begin
        g0[i]:=true;
        h0[j]:=true;
      end;
    end;
    readln;
  end;
  for i:=1 to n do
    i1:=0; j1:=0;
    for j:=1 to n do begin
      if a[i,j]='1' then begin
        if g0[j] then i1:=j;
      end else begin
        if g[j] then j1:=j;
      end;
    end;
    if (i1*j1)>0 then begin
      write(i,' ');
      for j:=1 to n do
        
    end;
  end;
  for i:=1 to n do if dfs(1,i) then halt(0);
  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to n do
        if (i<>j)and(a[i,j]='0')and(a[i,k]='1')and(a[k,j]='1') then begin
          writeln(j,' ',i,' ',k);
          halt(0);
        end;
  for i:=1 to n do
    for j:=1 to n do
      if (i<>j)and(a[i,j]       }
  write(-1);
{$IFNDEF ONLINE_JUDGE}
  close(input);
  close(output);
{$ENDIF}
end.