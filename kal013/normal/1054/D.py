n,k=map(int,raw_input().split())
l=map(int,raw_input().split())
pref=[0]
x=(1<<k)-1 
tem={}
for i in l:
    pref.append(pref[-1]^i)

ans=n*(n+1)
ans/=2

tt=0 
vis={}
for u in pref:
    try:
        tem[u]+=1 
    except:
        tem[u]=1 

for i in tem:
    if i in vis:
        
        continue
    
    kk=tem[i]
    if x^i in tem:
        kk+=tem[x^i]
    vis[i]=1 

    vis[x^i]=1
    if kk<=2:
        continue
    m1=kk/2 
    m2=kk-m1
    tt+=(m1*(m1-1))/2 +(m2*(m2-1))/2 
print ans-tt