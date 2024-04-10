a,b=map(int,input().split())
if b>a:
    print(-1)
else:
    a=a//2+a%2
    print(((a-1)//b+1)*b)