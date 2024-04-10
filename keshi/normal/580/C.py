n,k=map(int,input().split())
a=n*[0]
for i in range(n):
    a[i]=[]
e=list(map(int,input().split()))
g=list(range(n))
for i in range(n-1):
    b=list(map(int,input().split()))
    a[b[0]-1]+=[b[1]-1]
    a[b[1]-1]+=[b[0]-1]
r=0
see=n*[-1]
see[0]=e[0]
q=[0]
while q:
    w=q.pop(0)
    if see[w]<=k:
        for i in a[w]:
            if see[i]==-1:
                see[i]=(see[w]+e[i])*e[i]
                q+=[i]
        if w!=0 and len(a[w])<2:
            r+=1
print(r)