def move(a, i):
    a = list(a)
    q, r = divmod(a[i], len(a))
    a[i] = 0
    for it in xrange(r):
        i = (i + 1) % len(a)
        a[i] += 1
    for j in xrange(len(a)):
        a[j] += q
    return sum(v for v in a if v % 2 == 0)
a = map(int, raw_input().split())
print max(move(a, i) for i in xrange(len(a)) if a[i])