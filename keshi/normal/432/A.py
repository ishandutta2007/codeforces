n,k=map(int,input().split())
a=list(map(int,input().split()))
f=0
for i in a:
    if i+k<=5:
        f+=1
print(f//3)