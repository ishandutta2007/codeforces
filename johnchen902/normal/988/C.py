from collections import defaultdict
from itertools import islice
n = int(input())

b = defaultdict(dict)
for i in range(n):
    m = int(input())
    a = list(map(int, input().split()))
    suma = sum(a)
    for j, x in enumerate(a):
        b[suma - x][i] = j

for c in b.values():
    if len(c) >= 2:
        (i, j), (k, l) = islice(c.items(), 2)
        print("YES")
        print(i + 1, j + 1)
        print(k + 1, l + 1)
        break
else:
    print("NO")