t=int(input())
for _ in range(t):
    mod=1000000007
    x=int(input())
    r=input()
    n=len(r)
    s=[]
    for i in range(n):
        s.append(r[i])    
    f=True
    for i in range(1,x+1):
        o=ord(s[i-1])-ord('0')
        if(f):
            for j in range(1,o):
                for k in range(i,n):
                    s.append(s[k])
            n=len(s)
        else:
            if(o==2):
                n+=(n-i)
                n%=mod
            elif(o==3):
                n+=(2*(n-i))
                n%=mod
        if(n>x and f):
            f=False
    print(n)