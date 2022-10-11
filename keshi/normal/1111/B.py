def get():
    return list(map(int,input().split()))
n,k,m=get()
a=get()
a.sort()
c=(n+1)*[0]
c[0]=0
for i in range(1,n+1):
    c[i]=c[i-1]+a[i-1]
f=(c[n]-c[0]+min(m,n*k))/n
for i in range(1,n):
    if m-i>=0:
        f=max((c[n]-c[i]+min(m-i,(n-i)*k))/(n-i),f)
print(f)