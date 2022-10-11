a=list(map(int,input().split()))
a=[a[:2],a[2:]]
a.sort()
b=a[:]
if a[0][0]==a[1][0]:
    a[1]=[a[1][0]+a[1][1]-a[0][1],a[1][1]]
elif a[0][1]==a[1][1]:
    a[1]=[b[1][0],a[1][1]+a[1][0]-a[0][0]]
a+=[[a[0][0],a[1][1]],[a[1][0],a[0][1]]]
m=l=a[0][0]
for i in range(4):
    if a[i][0]>m:
        m=a[i][0]
    if a[i][0]<l:
        l=a[i][0]
x=m-l
m=l=a[0][1]
for i in range(4):
    if a[i][1]>m:
        m=a[i][1]
    if a[i][1]<l:
        l=a[i][1]
if m-l!=x:
    print(-1)
else:
    for i in a:
        if not i in b:
            print(*i,end=' ')