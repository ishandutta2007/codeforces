n, k = map(int, raw_input().strip().split())
vs = map(int, raw_input().strip().split())
vs.sort()

def okay(c4, c2, c1):
    ws = []
    for v in vs:
        r = min(c4, v / 4)
        c4 -= r
        v -= 4 * r
        ws.append(v)
    ws.sort()
    for v in ws:
        r = min(c2, v / 2)
        c2 -= r
        v -= 2 * r
        r = min(c1, v)
        c1 -= r
        v -= r
        r = min(c2, v)
        c2 -= r
        v -= r
        if v:
            return False
    return True


def solve():
    for i in xrange(n+1):
        c4 = i
        c2 = 2*n + n - i
        c1 = n - i
        if okay(i, 3*n - i, n - i): return True
    return False

print 'YES' if solve() else 'NO'