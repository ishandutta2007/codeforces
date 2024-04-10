input()
a=list(map(int,input().split()))
b=list(set(a))
m=0
for i in b:
    x=a.count(i)
    if x>m:
        m=x
print(m)