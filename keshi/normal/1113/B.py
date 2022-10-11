def get():
    return list(map(int,input().split()))
def pf(n): 
    a=[]
    i=1
    while i*i<n:
        if n%i==0:
            a+=[i]
            a+=[n//i]
        i+=1
    if i*i==n:
        a+=[i]
    return a
n=int(input())
b=get()
c=list(set(b))
a=101*[0]
for i in range(1,101):
    a[i]=pf(i)
s=sum(b)
c.sort()
m=c[0]
ans=0
for i in c:
    for j in a[i]:
        ans=max(ans,(j-1)*(i//j-m))
print(s-ans)