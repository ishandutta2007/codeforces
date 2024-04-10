n=int(input())
a=list(map(int,input().split()))
N=n+1
c=[0]*N
b=[0]*n
e={}
q=0
z=0
for i in range(N):
 e[i]=[]
for i in range(n):
 c[n-a[i]]+=1
 e[n-a[i]]+=[i]
for i in range(1,N):
 if c[i]%i>0:
  print('Impossible')
  exit(0)
 elif c[i]>0:
  z=i;
  for x in e[i]:
   if z==i:
    q+=1;z=0;
   z+=1
   b[x]=q;
print('Possible')
for x in b:
 print(x,end=' ')