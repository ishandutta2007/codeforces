from itertools import islice
def get_all(n):
    q = [(0, 1, 1, 1)]
    while q:
        a, b, c, d = q.pop()
        e, f = a + c, b + d
        if f <= n:
            yield e, f
            q.append((a, b, e, f))
            q.append((e, f, c, d))

def solve(n, m):
    x = list(islice(get_all(n), m))
    if len(x) == m >= n - 1:
        return x

res = solve(*map(int, input().split()))
if res is not None:
    print('Possible')
    for e in res: print(*e)
else:
    print('Impossible')