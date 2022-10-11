def ind(n):
    return int(n)%2
input()
a=list(map(ind,input().split()))
f=1
if a[:3].count(1)>=2:
    f=0
print(a.index(f)+1)