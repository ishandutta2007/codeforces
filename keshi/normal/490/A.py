n=int(input())
a=list(map(int,input().split()))
t=min(a.count(1),a.count(2),a.count(3))
print(t)
for i in range(t):
    r,b,c=a.index(1),a.index(2),a.index(3)
    print(r+1,b+1,c+1)
    a[r]=0
    a[b]=0
    a[c]=0