n=int(input())
s=input()
mod=998244353
if s==n*s[0]:
    print((n*(n+1)//2)%mod)
else:
    i=1
    while i<n and s[i]==s[0]:
        i+=1
    j=n-2
    while j>=0 and s[j]==s[-1]:
        j-=1
    j=n-j-1
    if s[0]==s[-1]:
        print((i+1)*(j+1)%mod)
    else:
        print((i+j+1)%mod)