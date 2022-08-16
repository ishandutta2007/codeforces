n=input()
l=map(int,raw_input().split())


def val(x):
    s=0
    for i in xrange(n):
        a=i+1
        s+=2*l[i]*(abs(a-x)+abs(x-1)+abs(a-1))
    return s 
ans=10**9
for i in xrange(1,n+1):
    ans=min(ans,val(i))
print ans