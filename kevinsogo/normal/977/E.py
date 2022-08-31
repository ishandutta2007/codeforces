def find(i):
    if parent[i] < 0:
        return i
    else:
        parent[i] = find(parent[i])
        return parent[i]

n, e = map(int, raw_input().split())
deg = [0]*n
parent = [-1]*n
for ee in xrange(e):
    a, b = map(int, raw_input().split())
    a -= 1; b -= 1
    deg[a] += 1
    deg[b] += 1
    a = find(a)
    b = find(b)
    if a != b:
        if parent[a] == parent[b]: parent[b] -= 1
        if parent[a] > parent[b]:
            parent[a] = b
        else:
            parent[b] = a

okay = [True]*n
for i in xrange(n):
    if deg[i] != 2: okay[find(i)] = False
print sum(okay[i] for i in set(map(find, xrange(n))))