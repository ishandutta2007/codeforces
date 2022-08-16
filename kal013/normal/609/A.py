n=input()
m=input()
a=[input() for i in xrange(n)]
a.sort()
cnt=0
s=0
a.sort()
curr=n-1
while s<m:
    s+=a[curr]
    curr-=1 
    cnt+=1 
print cnt