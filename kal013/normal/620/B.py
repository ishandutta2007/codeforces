l=[6,2,5,5,4,5,6,3,7,6]
def res(x):
    s=0
    t=str(x)
    for i in t:
        s+=l[int(i)]
    return s
a,b=map(int,raw_input().split())
ans=0
for i in xrange(a,b+1):
    ans+=res(i)
print ans