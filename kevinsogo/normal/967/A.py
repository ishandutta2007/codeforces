from itertools import *
n, s = map(int, input().split())
times = []
for i in range(n):
    h, m = map(int, input().split())
    times.append((h * 60 + m))

times.sort()
for t in count():
    if all(abs(u - t) > s for u in times):
        print(*divmod(t, 60))
        break