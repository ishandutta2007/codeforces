a,b=map(int,input().split())
a=10**(a-1)
if (a//b+1)*b>=a*10:
    print(-1)
else:
    print((a//b+1)*b)