n,m,k=map(int,input().split())
a=n*[0]
d=n*[0]
f=-1
for i in range(n):
    a[i]=input()
    d[i]=list(a[i])
    if f==-1:
        if '.' in a[i]:
            f=[i,a[i].index('.')]
if k:
    see=n*[1]
    for i in range(n):
        see[i]=m*[1]
    see[f[0]][f[1]]=0
    o=0
    q=[f]
    while o<len(q):
        w=q[o]
        if w[0]>0:
            if a[w[0]-1][w[1]]=='.' and see[w[0]-1][w[1]]:
                q+=[[w[0]-1,w[1]]]
                see[w[0]-1][w[1]]=0
        if w[0]<n-1:
            if a[w[0]+1][w[1]]=='.' and see[w[0]+1][w[1]]:
                q+=[[w[0]+1,w[1]]]
                see[w[0]+1][w[1]]=0
        if w[1]>0:
            if a[w[0]][w[1]-1]=='.' and see[w[0]][w[1]-1]:
                q+=[[w[0],w[1]-1]]
                see[w[0]][w[1]-1]=0
        if w[1]<m-1:
            if a[w[0]][w[1]+1]=='.' and see[w[0]][w[1]+1]:
                q+=[[w[0],w[1]+1]]
                see[w[0]][w[1]+1]=0
        o+=1
    for i in q[-k:]:
        d[i[0]][i[1]]='X'
for i in range(n):
    r=''
    for j in d[i]:
        r+=j
    print(r)