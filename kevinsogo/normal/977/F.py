from collections import *
input()
a = list(map(int, input().split()))
m = defaultdict(int)
for x in reversed(a): m[x] = m[x + 1] + 1
v = max(m.keys(), key=m.get)
seq = []
for i, x in enumerate(a):
    if v == x:
        seq.append(i + 1)
        v += 1
print(len(seq))
print(*seq)