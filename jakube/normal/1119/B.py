f=lambda:map(int,input().split());n,k=f();a=*f(),
while sum(sorted(a[:n])[::-2])>k:n-=1
print(n)