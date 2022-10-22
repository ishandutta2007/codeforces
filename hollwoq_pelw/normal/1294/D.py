import sys
from heapq import *
input = sys.stdin.readline

quer, m = map(int, input().split())

vals = list(range(m))
q = []
for v in vals:
    heappush(q, v)

out = []
for _ in range(quer):
    nex = int(input()) % m
    vals[nex] += m
    heappush(q, vals[nex])

    new = heappop(q)
    while vals[new % m] != new:
        new = heappop(q)

    out.append(new)
    heappush(q, new)

print('\n'.join(map(str,out)))