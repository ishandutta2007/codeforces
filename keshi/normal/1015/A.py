n,m=map(int,input().split())
a=list(range(1,m+1))
for i in range(n):
    s,l=map(int,input().split())
    for j in range(s,l+1):
        if j in a:
            a.remove(j)
print(len(a))
print(*a)