m=input
r=range
a,b,c=map(int,m().split())
e=[m()for i in r(a)]
s=0
for j in r(b):
 w=0
 for i in r(a):
  if e[i][j]=='Y':
   w+=1
 if w>=c:
  s+=1
print(s)
#kitten