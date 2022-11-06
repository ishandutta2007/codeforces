w, h = map(int,raw_input().split())
a = []
for i in xrange(h):
    a.append(raw_input())
for i in xrange(2 * w):
    print ''.join((a[j / 2][i / 2] for j in xrange(2 * h)))