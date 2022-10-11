n,k=map(int,input().split())
s=int((96-0.4*k)**0.5)
f=96-0.4*k
while s*(s+1)>f:
    s-=1
print(min(n,s))