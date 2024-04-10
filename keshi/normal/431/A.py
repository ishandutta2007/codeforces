a=list(map(int,input().split()))
f=0
for i in input():
    f+=a[int(i)-1]
print(f)