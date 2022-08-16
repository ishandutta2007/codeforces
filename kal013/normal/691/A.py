n=input()
l=map(int,raw_input().split())
if ((n==1 and sum(l)==1) or (n!=1 and sum(l)==n-1)):
    print "YES"
else:
    print "NO"