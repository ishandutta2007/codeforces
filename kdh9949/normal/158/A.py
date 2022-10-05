get=lambda:map(int,input().split())
n,k=get()
a=list(get())
ans=0
for i in a:
    if i>=a[k-1] and i>0:
        ans+=1
print(ans)