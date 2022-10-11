a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
for i in range(2):
    if a>b:
        a,b=b,a
    if b>c:
        b,c=c,b
w=[b[:]]
while not (a[0]<=b[0]<=c[0] and min(a[1],c[1])<=b[1]<=max(a[1],c[1])):
    if not a[0]<=b[0]<=c[0]:
        if b[0]<a[0]:
            b[0]+=1
        else:
            b[0]-=1
    elif not min(a[1],c[1])<=b[1]<=max(a[1],c[1]):
        if b[1]<min(c[1],a[1]):
            b[1]+=1
        else:
            b[1]-=1
    w+=[b[:]]
while not a==b:
    w+=[a[:]]
    if a[0]!=b[0]:
        if a[0]<b[0]:
            a[0]+=1
        else:
            a[0]-=1
    elif a[1]!=b[1]:
        if a[1]<b[1]:
            a[1]+=1
        else:
            a[1]-=1
while not c==b:
    w+=[c[:]]
    if c[0]!=b[0]:
        if c[0]<b[0]:
            c[0]+=1
        else:
            c[0]-=1
    elif c[1]!=b[1]:
        if c[1]<b[1]:
            c[1]+=1
        else:
            c[1]-=1
w.sort()
print(len(w))
for i in w:
    print(i[0],i[1])