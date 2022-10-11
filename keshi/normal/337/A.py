n,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
s=a[-1]-a[0]
for i in range(m-n+1):
    f=a[i+n-1]-a[i]
    if f<s:
        s=f
print(s)