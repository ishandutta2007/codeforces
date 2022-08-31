s=raw_input()
l=[i for i in xrange(len(s)+1)]

m=input()
for i in xrange(m):
    a,b,k=map(int,raw_input().split())
    tmp=l[a:b+1]
    n=b-a+1
    for j in xrange(n):
        l[a+j]=tmp[(j-k)%n]
s2=""
for i in xrange(1,len(s)+1):
    s2+=s[l[i]-1]
print s2