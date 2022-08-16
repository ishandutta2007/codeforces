n=input()
l=map(int,raw_input().split())
mex=0
for i in xrange(len(l)):
    if l[i]>mex:
        print i+1
        break
    mex=max(mex,l[i]+1)
else:
    print -1