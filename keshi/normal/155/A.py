n=int(input())
a=list(map(int,input().split()))
b=[a[0]]
f=0
for i in range(1,n):
    if a[i]>b[-1] or a[i]<b[0]:
        f+=1
    b+=[a[i]]
    b.sort()
print(f)