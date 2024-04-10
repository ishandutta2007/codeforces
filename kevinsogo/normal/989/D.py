n, l, wmax = map(int, raw_input().split())
cs = []
for i in xrange(n):
    x, v = map(int, raw_input().split())
    cs.append((x, v))

poss = sorted([-x for x, v in cs if v == +1])
negs = sorted([-x for x, v in cs if v == -1])
ans = 0
for x in poss:
    if wmax == 1 and x <= 0: continue
    lf = max(-x, -x * (wmax - 1) / (wmax + 1))
    if wmax != 1: lf = max(lf, -x * (wmax + 1) / (wmax - 1))
    L, R = -1, len(negs)
    while R - L > 1:
        M = L + R >> 1
        if negs[M] >= l - lf:
            R = M
        else:
            L = M
    ans += R
print ans