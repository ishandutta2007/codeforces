n,x,y=map(int,input().split())
a=list(map(int,input().split()))
if x>y:
    s=0
    for i in a:
        s+=i
    d=s/(x-y)
    if d>10**100:
        a.sort()
        s=0
        g=1
        for i in range(a):
            s+=(a[i]-1)%(x-y)
            if s>10**100:
                print(i)
                g=0
                break
        if g:
            print(n)
    else:
        print(n)
else:
    f=0
    for i in a:
        if i<=x:
            f+=1
    print((f-1)//2+1)