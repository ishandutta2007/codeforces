import math

q = int(input())
for _ in range(q):
    k, n, a, b = map(int, input().split())
    out = math.floor((k-(n*b)-1)/(a-b));
    if out < 0:
        print(-1)
    else:
        print(min(n, out))