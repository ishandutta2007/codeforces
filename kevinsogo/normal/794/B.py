from math import *

n, h = map(int, raw_input().strip().split())
ans = [sqrt(float(i) / n) * h for i in xrange(1, n)]
print ' '.join('%.11f' % v for v in ans)