n,m=map(int,raw_input().split())
l=[0 for i in xrange(m)]
a=map(int,raw_input().split())
for i in a:
    l[i-1]+=1 
ans=0
cnt=0
for i in l:
    ans+=i*cnt 
    cnt+=i 
print ans