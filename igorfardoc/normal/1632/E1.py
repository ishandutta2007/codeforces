import sys


sys.setrecursionlimit(3100)

g = []
depth = []
parent = []
deepest = []
vct = []
inf = 1000000000
n = 0
ans = []


def dfs1(v, p, h):
    global parent, depth, deepest
    parent[v] = p
    depth[v] = h
    deepest[v] = h
    i = 0
    while i < len(g[v]):
        to = g[v][i]
        if to == p:
            del g[v][i]
            continue
        dfs1(to, v, h + 1)
        deepest[v] = max(deepest[v], deepest[to])
        i += 1


def solve():
    k = len(vct)
    pref = [0 for _ in range(k)]
    pref[0] = vct[0]
    for i in range(1, k):
        pref[i] = max(pref[i - 1], vct[i])
    for x in range(k - 1, n + 1):
        ans[x] = min(ans[x], pref[k - 1])
    curr = 0
    pos = k
    for x in range(k - 2, 0, -1):
        curr -= 1
        if (k - 2 - x) % 2 == 0:
            pos -= 1
            curr = max(curr, vct[pos] - 1)
        ans[x] = min(ans[x], max(curr, pref[pos - 1]))


def dfs2(v):
    global deepest, depth, parent
    vct.append(deepest[v])
    solve()
    del vct[-1]
    maxx = depth[v]
    son = -1
    maxx2 = -1
    for to in g[v]:
        if deepest[to] > maxx:
            maxx2 = maxx
            maxx = deepest[to]
            son = to
        elif deepest[to] > maxx2:
            maxx2 = deepest[to]
    for to in g[v]:
        if to == son:
            vct.append(maxx2)
            dfs2(to)
            del vct[-1]
        else:
            vct.append(maxx)
            dfs2(to)
            del vct[-1]


for _ in range(int(input())):
    n = int(input())
    g = [[] for _ in range(n)]
    depth = [0 for _ in range(n)]
    parent = [0 for _ in range(n)]
    deepest = [0 for _ in range(n)]
    for i in range(n - 1):
        v, u = map(int, input().split())
        v -= 1
        u -= 1
        g[v].append(u)
        g[u].append(v)
    dfs1(0, 0, 0)
    ans = [inf for _ in range(n + 1)]
    dfs2(0)
    for x in range(1, n + 1):
        print(ans[x], end=' ')
    print()