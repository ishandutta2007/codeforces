n,m=[int(i) for i in input().split()]
x=[]
flag=True
flaga=False
for _ in range(m):
    a,b=[int(i) for i in input().split()]
    x.append([a,b])
i=x[0]
for l in range(m):
    if not (x[l][0] in i or x[l][1] in i):
        j=x[l]
        flag=False
        break
if flag:
    flaga=True
else:
    pa=[]
    for s in i:
        for d in j:
            pa.append([s,d])
    for s in pa:
        flag=True
        for l in range(m):
            if not (x[l][0] in s or x[l][1] in s):
                j=x[l]
                flag=False
                break
        if flag:
            flaga=True
            break
if flaga:
    print("YES")
else:
    print("NO")