n, d = map(int, input().split())
m = int(input())
ans = 0
for i in range(m):
    x, y = map(int, input().split())
    if y > x + d or y < x - d or y < -x + d or y > -x + 2 * n - d:
        print('NO')
    else:
        print('YES')