n=input()
l=map(int,raw_input().split())
r=map(int,raw_input().split())
temp=[n-l[i]-r[i] for i in xrange(n)]
s=[l[i]+r[i] for i in xrange(n)]
if l[0]!=0 or r[-1]!=0:
    print "NO"
elif max(s)>n-1:
    print "NO"
else:
    for i in xrange(n):
        l1=0
        r1=0
        for j in xrange(i):
            if temp[j]>temp[i]:
                l1+=1 
        for j in xrange(i+1,n):
            if temp[j]>temp[i]:
                r1+=1 
        if l1!=l[i] or r1!=r[i]:
            print "NO"
            break
    else:
        print "YES"
        for i in temp:
            print i,
        print