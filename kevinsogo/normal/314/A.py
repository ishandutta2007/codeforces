n, k = map(int, raw_input().strip().split())
a = map(int, raw_input().strip().split())

s = 0
i = 1
for w in xrange(1,n+1):
  d = s - (n-i)*a[w-1]*(i-1)
#  print 'delta', w, d, s
  if d < k:
    print w
    n -= 1
  else:
    s += a[w-1] * (i-1)
    i += 1