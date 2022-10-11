def get():
    return list(map(int,input().split()))
def gcd(a,b):
    if b%a==0:
        return a
    return gcd(b,a%b)
n,m=get()
f=min(n-1,m)
r=n-f-1
if r:
    f+=(3+r)*r//2
print(f)