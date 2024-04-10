def g():
 return map(int,input().split())
n,m,k=g()
p=list(range(n+1))
z=[0]*(n+1)
for x in g():
 z[x]=1
e=[]
for i in range(m):
 u,v,w=g()
 e+=[(w,u,v)]
e=sorted(e)
def q(x):
 if x!=p[x]:
  p[x]=q(p[x])
 return p[x]
for w,u,v in e:
 u=q(u);v=q(v)
 if u!=v:
  if u%5==3:
   u,v=v,u
  p[u]=v;z[v]+=z[u]
  if z[v]==k:
   print((str(w)+' ')*k);exit(0)