def gcd(a,b):
    if b%a==0:
        return a
    return gcd(b%a,a)
a,b,n=map(int,input().split())
while n:
    n-=gcd(a,n)
    if n:
        n-=gcd(b,n)
        if not n:
            print(1)
            break
    else:
        print(0)
        break