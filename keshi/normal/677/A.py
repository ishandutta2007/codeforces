n,b=map(int,input().split())
a=list(map(int,input().split()))
for i in a:
    if i>b:
        n+=1
print(n)