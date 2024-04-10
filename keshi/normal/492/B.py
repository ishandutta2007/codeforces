a,b=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
a=[0-a[0]]+a+[b-a[-1]+b]
l=0
for i in range(1,len(a)):
    if a[i]-a[i-1]>l:
        l=a[i]-a[i-1]
print(l/2)