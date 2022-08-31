for t in xrange(input()):
    n=input()
    res=n*(n+1)/2 
    po=0 
    while(1<<po)<=n:
        po+=1 
    tmp=(1<<(po))-1
    res-=2*tmp 
    print res