x, d = map(int, raw_input().split())
val = 1
arr = []
for k in xrange(80-1,0,-1):
    while x >= (1 << k) - 1:
        x -= (1 << k) - 1
        arr += [val]*k
        val += d + 10

assert x == 0
print len(arr)
print ' '.join(map(str, arr))