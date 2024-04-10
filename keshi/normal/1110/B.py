def get():
    return list(map(int,input().split()))
n,m,k=get()
a=get()
b=(n-1)*[0]
for i in range(1,n):
    b[i-1]=[a[i]-a[i-1],i]
d=[0]
b.sort(reverse=1)
for i in range(k-1):
    s=b.pop(0)
    d+=[s[1]]
d+=[n]
f=0
for i in range(1,len(d)):
    f+=a[d[i]-1]-a[d[i-1]]+1
print(f)