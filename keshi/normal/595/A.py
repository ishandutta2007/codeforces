n,m=map(int,input().split())
f=0
for i in range(n):
    a=list(map(int,input().split()))
    for i in range(m):
        if 1 in a[2*i:2*i+2]:
            f+=1
print(f)