n=input()
l=map(int,raw_input().split())
print n+1 
print 1,n,900000
#arr=[l[i]+900000 for i in xrange(n)]
for i in xrange(n):
    print 2,i+1,l[i]-i-1+900000