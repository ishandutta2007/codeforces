import sys
import fractions
n = int(input())
refs = [0] * n
used = [0] * n
to = [int(x)-1 for x in input().split(' ')]
for i in to:
    refs[i] += 1

times = []
max_a = 0
depth = [-1] * n

def dfs(u, d, depth):
    if depth[u] != -1:
        loop = d - depth[u]
        times.append(loop)
        global max_a
        if max_a < depth[u]:
            max_a = depth[u]
        return
    used[u] = True
    depth[u] = d
    return dfs(to[u], d+1, depth)

for i in range(n):
    if refs[i] == 0:
        depth = [-1] * n
        b = dfs(i, 0, depth)

for i in range(n):
    if not used[i]:
        depth = [-1] * n
        b = dfs(i, 0, depth)


lcm = 1
for t in times:
    lcm = lcm * t // fractions.gcd(lcm, t)

ans = lcm
while ans < max_a:
    ans += lcm
print(ans)