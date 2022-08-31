n, p = map(int, raw_input().split())
a = [int(x) if x != '.' else -1 for x in raw_input()]
good = False
found = 0
for i in xrange(p):
    for j in xrange(i, n, p):
        if a[j] != -1:
            found = a[j]
    for j in xrange(i, n, p):
        if a[j] == -1:
            found ^= 1
            a[j] = found

    if len(set(a[i: n: p])) >= 2:
        good = True

print ''.join(map(str, a)) if good else 'No'