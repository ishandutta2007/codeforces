n,k=map(int,input().split())
a=list(map(int,input().split()))
m=0
s=sum(a)
for i in range(k):
    f=0
    for j in range(i,n,k):
        f+=a[j]
    if abs(f-s)>m:
        m=abs(f-s)
print(m)