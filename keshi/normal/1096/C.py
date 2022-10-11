def gcd(a,b):
    if b%a==0:
        return a
    return gcd(b%a,a)
n=int(input())
for i in range(n):
    a=int(input())
    b=180//gcd(a,180)
    c=b
    while a//(180/b)>b-2:
        b+=c
    print(b)