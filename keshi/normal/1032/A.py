n,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(set(a))
m=0
for i in b:
    x=a.count(i)
    if x>m:
        m=x
print((m-1+k)//k*len(b)*k-n)