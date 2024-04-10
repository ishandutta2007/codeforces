n,x=map(int,input().split())
i=1
f=0
while i*i<=x and i<=n:
    if x%i==0 and x//i<=n:
        f+=1
        if i*i==x:
            f-=0.5
    i+=1
print(int(f*2))