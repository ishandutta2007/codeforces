for t in range(int(input())):
    def toT(s):
        return int(s[:2])*60+int(s[-2:])
    def toS(x):
        return f"{x//60:02d}:{x%60:02d}"
    def isPal(s):
        return s==s[::-1]
    x,dif = input().split()
    x=toT(x)
    dif=int(dif)
    y = x+24*60
    ans=0
    while y!=x:
        y%=24*60
        ans+=isPal(toS(y))
        y+=dif
        y%=24*60
    print(ans)