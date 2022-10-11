def get():
    return map(int,input().split())
n,k=get()
a=list(get())
s=input()
i=0
dmg=0
while i<n:
    j=i+1
    while j<n and s[i]==s[j]:
        j+=1
    j-=1
    if j-i+1<=k:
        dmg+=sum(a[i:j+1])
    else:
        g=a[i:j+1]
        g.sort()
        dmg+=sum(g[len(g)-k:])
    i=j+1
print(dmg)