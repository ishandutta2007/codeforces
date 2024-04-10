import math
n=int(input())
if (n==1):
    print(1)
    exit(0)
f=[]
lst=[]
act=[]
def Albedo(x,g):
    for i in range(50100):
        x.append([])
        for j in range(25):
            x[-1].append(g)
Albedo(f,0.0)
Albedo(lst,0)
Albedo(act,0)
vis=[0 for i in range(0,100010)]
prim=[0 for i in range(0,100010)]
lg=[0.0 for i in range(0,100010)] 
len=0
for i in range(2,50):
    if (vis[i]==0):
        len+=1
        prim[len]=i
        for j in range(1,int(100//i)+1):
            vis[i*j]=1
for i in range(1,len+1):
    lg[prim[i]]=math.log(prim[i])
f[1][1]=0.0
for i in range(2,n+1):
    f[i][1]=f[i-1][1]+lg[2]
for i in range(2,len+1):
    x=0
    for g in range(len+1,1,-1):
        x=0
        for j in range(2,n+1):
            x=x+lg[prim[i]]
            if (n % j!=0):
                continue
            for k in range(1,int(n//j)+1):
                if (f[k*j][g]==0):
                    if (f[k][g-1]!=0):
                        f[k*j][g]=f[k][g-1]+x
                        lst[k*j][g]=k
                        act[k*j][g]=prim[i]
                else:
                    if (f[k][g-1]+x<f[k*j][g]):
                      if (f[k][g-1]!=0):
                         f[k*j][g]=f[k][g-1]+x
                         lst[k*j][g]=k
                         act[k*j][g]=prim[i]
up=100000000.0
for i in range(1,len+1):
    if (f[n][i]<up):
        if (f[n][i]!=0):
            up=f[n][i]
            id=i
now=n
ans=1
for j in range(id,1,-1):
    fre=now//lst[now][j]
    for k in range(0,fre-1):
        ans=ans*act[now][j]
    now=lst[now][j]
for i in range(1,now):
    ans=ans*2
print(ans)