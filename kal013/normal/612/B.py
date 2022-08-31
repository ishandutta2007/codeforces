n=input()
l=map(int,raw_input().split())
d={}
for i in xrange(len(l)):
    d[l[i]]=i+1 
ans=0
curr=d[1]
for i in xrange(2,n+1):
    ans+=abs(curr-d[i])
    curr=d[i]
print ans