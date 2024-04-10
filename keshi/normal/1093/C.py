n=int(input())
a=list(map(int,input().split()))
b=n*[0]
b[-1]=a[0]
for i in range(1,len(a)):
    x=i
    y=n-i-1
    r=a[i]-b[x-1]
    if r>b[y+1]:
        r=b[y+1]
    t=a[i]-r
    b[x]=t
    b[y]=r
print(*b)