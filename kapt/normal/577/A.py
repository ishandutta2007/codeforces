n, x = map(int, input().split())

cnt = 0
from math import sqrt
for i in range(1, int(sqrt(x)) + 1):
    j = x // i
    if i * j == x and i <= n and j <= n:
        cnt += 2
        if i == j:
            cnt -= 1
print(cnt)