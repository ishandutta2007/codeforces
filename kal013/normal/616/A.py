a=raw_input()
b=raw_input()
l=[int(a[i]) for i in xrange(len(a)-1,-1,-1)]
while (len(l) and l[-1]==0):
    l.pop()
l2=[int(b[i]) for i in xrange(len(b)-1,-1,-1)]
while (len(l2) and l2[-1]==0):
    l2.pop()
n=len(l)
m=len(l2)
if n>m:
    print ">"
elif m>n:
    print "<"
else:
    tmp=0
    for i in xrange(n-1,-1,-1):
        if l[i]>l2[i]:
            print ">"
            break
        elif l[i]<l2[i]:
            print "<"
            break
    else:
        print "="