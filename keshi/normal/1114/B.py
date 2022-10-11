def get():
    return list(map(int,input().split()))
n,m,k=get()
a=get()
b=sorted(a)
c=b[-(m*k):]
f=c.count(c[0])
r=0
s=sum(b[-(m*k):])
l=[]
for i in range(n):
    if a[i]>c[0] or (a[i]==c[0] and f>0):
        if a[i]==c[0]:
            f-=1
        r+=1
        if r==m:
            r=0
            l+=[i+1]
print(s)
print(*l[:k-1])