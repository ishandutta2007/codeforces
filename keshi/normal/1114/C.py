def get():
    return list(map(int,input().split()))

def pf(n): 
    a=[]
    while n % 2 == 0: 
        a+=[2]
        n = n / 2
    
    for i in range(3,int(n**0.5)+1,2):
        while n % i== 0: 
            a+=[i]
            n = n / i 
    if n > 2: 
        a+=[n]
    return a
n,b=get()
d=n
c=b
a=list(set(pf(b)))
m=n
for k in a:
    n=d
    b=c
    s=0
    while n>=k:
        s+=n//k
        n//=k
    f=0
    while b%k==0:
        b//=k
        f+=1
    s//=f
    m=min(s,m)
print(int(m))