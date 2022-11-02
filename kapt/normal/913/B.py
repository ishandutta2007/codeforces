n = int(input())
g = [[] for i in range(n)]
for i in range(n - 1):
    v = int(input())
    g[i + 1].append(v - 1)
    g[v - 1].append(i + 1)
for i in range(n):
    cnt = 0
    for u in g[i]:
        if len(g[u]) == 1:
            cnt += 1
    if not(len(g[i]) == 1) and not(cnt >= 3):
        print('No')
        exit()
print('Yes')