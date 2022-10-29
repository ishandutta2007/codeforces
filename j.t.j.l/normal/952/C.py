def fa(p):
    for i in range(1,len(p)):
        dd = p[i] - p[i-1]
        if dd < 0:
            dd = -dd
        if dd >= 2:
            return 1
    return 0

n=int(input())
a=list(map(int, input().split()))
b=[]
flag = 1
if fa(a):
    flag = 0
for i in range(n):
    c = []
    k = 0
    for j in range(len(a)):
        if (a[j] > a[k]):
            k = j
    b.append(a[k])
    for j in range(len(a)):
        if j != k:
            c.append(a[j])
    a = c
    if fa(a):
        flag = 0
    if fa(b):
        flag = 0
if flag:
    print("YES")
else:
    print("NO")