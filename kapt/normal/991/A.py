a, b, c, n = map(int, input().split())
n -= 1
d = n - a - b + c
if c > n:
    print(-1)
elif c > b or c > a:
    print(-1)
elif d < 0:
    print(-1)
else:
    print(d + 1)