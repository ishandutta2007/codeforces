n=int(input())
a=sorted(map(int,input().split()))
f=0
for i in range(0,n,2):
    f+=a[i+1]-a[i]
print(f)