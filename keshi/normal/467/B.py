def bi(n,x):
    a=[]
    while n:
        a+=[n%2]
        n//=2
    a.reverse()
    a=[0]*(x-len(a))+a
    return a
def check(a,b,k):
    f=0
    for i in range(len(a)):
        if a[i]!=b[i]:
            f+=1
            if f>k:
                return 0
    return 1
a=list(map(int,input().split()))
b=(a[1]+1)*[0]
for i in range(a[1]+1):
    b[i]=int(input())
s=bi(b[-1],a[0])
f=0
for i in range(a[1]):
    if check(s,bi(b[i],a[0]),a[2]):
        f+=1
print(f)