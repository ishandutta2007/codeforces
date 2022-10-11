def tn(n):
    if n:
        return tn(n//10)+1
    return 0
n,k=map(int,input().split())
if k>n*9 or k==0 and n>1:
    print(-1,-1)
else:
    s=''
    d=[]
    f=k
    while f-9>0:
        f-=9
        s='9'+s
    s+=str(f)
    s+=(n-len(s))*'0'
    d=s[::-1]
    if d[0]=='0' and len(d)>1:
        d=int(d)
        d-=10**(tn(d)-1)
        d=str(d)
        if len(d)<n:
            d='1'+(n-len(d)-1)*'0'+d
    print(d,s)