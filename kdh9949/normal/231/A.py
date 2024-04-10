n=int(input())
ans=0
for i in range(n):
    a=list(map(int,input().split()))
    if a[0]+a[1]+a[2]>1:
        ans+=1
print(ans)