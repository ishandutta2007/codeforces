n, e = map(int, input().split())
r = list(map(int, input().split()))
deg = [0]*n
for ee in range(e):
    x, y = map(int, input().split())
    x -= 1; y -= 1
    if r[x] == r[y]: continue
    if r[x] < r[y]: x, y = y, x
    deg[x] += 1
inds = sorted(range(n), key=lambda i: r[i])
j = 0
ans = [0]*n
for i in inds:
    while r[inds[j]] < r[i]: j += 1
    ans[i] = j - deg[i]
print(*ans)