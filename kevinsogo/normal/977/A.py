n, k = map(int, raw_input().split())
for it in xrange(k):
    n = n / 10 if n % 10 == 0 else n - 1
print n