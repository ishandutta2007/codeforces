n, m = map(int, input().split())
a = [input() for i in range(n)]
x1 = y1 = 10 ** 10
x2 = y2 = -1
cnt = 0
for i in range(n):
    for j in range(m):
        if a[i][j] == 'B':
            x1 = min(x1, i)
            x2 = max(x2, i)
            y1 = min(y1, j)
            y2 = max(y2, j)
            cnt += 1
dx = x2 - x1 + 1
dy = y2 - y1 + 1
if cnt == 0:
    ans = 1
elif max(dx, dy) <= min(n, m):
    ans = max(dx, dy)**2 - cnt
else:
    ans = -1
print(ans)