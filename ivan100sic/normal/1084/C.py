m=10**9+7;x=1;y=0
for c in input():
 z=(x+y)%m
 if c=='a':
  y=z
 elif c=='b':
  x=z;y=0
print((x+y+m-1)%m)