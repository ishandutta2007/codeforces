from heapq import heappushpop
n, k = map(int, input().split())
ps = list(map(int, input().split()))
cs = list(map(int, input().split()))
coins = [0]*k
indices = sorted(range(n), key=(lambda i: ps[i]), reverse=True)
ans = list(cs)
s = 0
for i in reversed(indices):
    while ps[indices[-1]] < ps[i]:
        c = cs[indices.pop()]
        s += c - heappushpop(coins, c)
    ans[i] += s
print(*ans, sep=' ')