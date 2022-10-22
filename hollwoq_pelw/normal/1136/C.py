n, m = [int(k) for k in input().split()]
a = [[int(k) for k in input().split()] for _ in range(n)]
b = [[int(k) for k in input().split()] for _ in range(n)]

x = [[] for _ in range(n+m-1)]
y = [[] for _ in range(n+m-1)]

for i in range(n):
    for j in range(m):
        x[i+j].append(a[i][j])
        y[i+j].append(b[i][j])

bl = []

for i in range(n+m-1):
    bl.append(sorted(x[i]) == sorted(y[i]))

if (all(bl)): print("YES")
else: print("NO")