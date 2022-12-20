program q;    {$Q- $R-}
var i,j,k,n,i1,j1,i2,j2,f,l,p,top,h1:longint;
m,c,h:array[0..301,0..301]of longint;
t,s,o,tx,ty,sx,sy:array[0..190000]of longint;
procedure quicksort(first,last:longint);
var f,l,x,y,mid:longint;
begin
  f:=first;
  l:=last;
  mid:=c[tx[(f+l) div 2],ty[(f+l) div 2]];
  repeat
     while c[tx[f],ty[f]]<mid do inc(f);
     while c[tx[l],ty[l]]>mid do dec(l);
     if f<=l
     then begin
            x:=tx[f];
            tx[f]:=tx[l];
            tx[l]:=x;
            y:=ty[f];
            ty[f]:=ty[l];
            ty[l]:=y;
            inc(f);
            dec(l)
           end;
  until f>l;
  if f<last
  then quicksort(f,last);
  if first<l
  then quicksort(first,l)

end;
Begin
 { assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  }read(i1,j1,p);
  for i:=1 to i1 do
  for j:=1 to j1 do
  begin
    read(m[i,j]);
    inc(t[m[i,j]]);
    if m[i,j]=1
    then c[i,j]:=i+j-2
    else c[i,j]:=999999999
  end;
  o[1]:=1;
  for k:=2 to p do
  o[k]:=o[k-1]+t[k-1];
  for i:=1 to i1 do
  for j:=1 to j1 do
  begin
     tx[o[m[i,j]]+s[m[i,j]]]:=i;
     ty[o[m[i,j]]+s[m[i,j]]]:=j;
     inc(s[m[i,j]])
  end;
  quicksort(1,o[1]+t[1]-1);
  for k:=2 to p do
  begin
  if t[k-1]*t[k]>i1*j1
  then begin
          for i:=1 to i1 do
          for j:=1 to j1 do
          if m[i,j]=k-1
          then h[i,j]:=c[i,j]
          else h[i,j]:=999999999;
          sx[1]:=tx[o[k-1]];
          sy[1]:=ty[o[k-1]];
          h1:=1;
          top:=1;
          f:=o[k-1]+1;
          repeat
          while (f<o[k]) and (c[sx[h1],sy[h1]]>=c[tx[f],ty[f]]) do
          begin
            inc(top);
            sx[top]:=tx[f];
            sy[top]:=ty[f];
            inc(f)
          end;
            for i:=-1 to 1 do
            for j:=-1 to 1 do
            if (abs(i)+abs(j)=1) and (h[sx[h1]+i,sy[h1]+j]>h[sx[h1],sy[h1]]+1)
            then begin
                   inc(top);
                   sx[top]:=i+sx[h1];
                   sy[top]:=j+sy[h1];
                   h[sx[h1]+i,sy[h1]+j]:=h[sx[h1],sy[h1]]+1
                 end;
            inc(h1);
            if (h1>TOP) and (f<o[k])
            then begin
                    inc(top);
            sx[top]:=tx[f];
            sy[top]:=ty[f];
            inc(f)
                  end;
          until top<h1;
          for i:=1 to i1 do
          for j:=1 to j1 do
          if m[i,j]=k
          then c[i,j]:=h[i,j]
        end
  else for i:=o[k-1] to o[k]-1 do
       for j:=o[k] to o[k]+t[k]-1 do
       if abs(tx[i]-tx[j])+abs(ty[i]-ty[j])+c[tx[i],ty[i]]<c[tx[j],ty[j]]
       then c[tx[j],ty[j]]:=abs(tx[i]-tx[j])+abs(ty[i]-ty[j])+c[tx[i],ty[i]];
       quicksort(o[k],o[k]+t[k]-1);
  end;
  for i:=1 to i1 do
  for j:=1 to j1 do
  if m[i,j]=p
  then write(c[i,j])

end.