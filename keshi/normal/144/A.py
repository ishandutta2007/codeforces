n=int(input())
a=list(map(int,input().split()))
m=max(a)
f=0
while a[0]!=m:
    x=a.index(m)
    a[x],a[x-1]=a[x-1],a[x]
    f+=1
m=min(a)
for i in range(len(a)-1,-1,-1):
    if a[i]==m:
        break
print(n-1-i+f)