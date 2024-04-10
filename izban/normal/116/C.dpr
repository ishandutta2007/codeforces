{$APPTYPE CONSOLE}
uses math;
var
  i,n,ans:integer;
  p,d:array[-1..2000]of integer;
  vis:array[-1..2000]of boolean;
function dfs(x:integer):integer;
begin
  if not vis[x] then  begin
    vis[x]:=true;
    if p[x]>-1 then begin
      d[x]:=dfs(p[x]);
    end;
    if p[x]=-1 then d[x]:=0;
  end;
  result:=d[x]+1;
end;
begin
{$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
{$ENDIF}

  read(n); ans:=0;
  for i:=1 to n do vis[i]:=false;
  for i:=1 to n do read(p[i]);
  for i:=1 to n do
    if not vis[i] then ans:=max(ans,dfs(i));
  writeln(ans);
{$IFNDEF ONLINE_JUDGE}
  close(input);
  close(output);
{$ENDIF}
end.