n, e = map(int, raw_input().strip().split())
adj1 = [[] for i in xrange(n)]
adj2 = [[] for i in xrange(n)]

for i in xrange(e):
    a, b, c = raw_input().strip().split()
    a = int(a) - 1
    b = int(b) - 1
    if c == 'B':
        adj1[a].append((b, 0))
        adj1[b].append((a, 0))
        adj2[a].append((b, 1))
        adj2[b].append((a, 1))
    else:
        adj1[a].append((b, 1))
        adj1[b].append((a, 1))
        adj2[a].append((b, 0))
        adj2[b].append((a, 0))

def res(adj):
    result = []
    color = [-1]*n
    for i in xrange(n):
        if color[i] >= 0: continue
        part = [[], []]
        queue = [i]
        color[i] = 0
        part[color[i]].append(i)
        f = 0
        while f < len(queue):
            i = queue[f]; f += 1
            for j, c in adj[i]:
                if color[j] >= 0:
                    if (color[i] == color[j]) != c:
                        return [0]*(n+1)
                else:
                    color[j] = color[i] if c else not color[i]
                    part[color[j]].append(j)
                    queue.append(j)

        result += min(part, key=lambda x: len(x))

    return result

ans = min(res(adj1), res(adj2), key=lambda x: len(x))

if len(ans) <= n:
    print len(ans)
    print ' '.join(str(v+1) for v in ans)
else:
    print -1