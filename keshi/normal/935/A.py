n=int(input())
i=1
f=-1
while i*i<=n:
    if n%i==0:
        f+=2
        if i*i==n:
            f-=1
    i+=1
print(f)