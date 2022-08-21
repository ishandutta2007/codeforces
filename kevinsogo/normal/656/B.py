input()
m = map(int, raw_input().strip().split())
r = map(int, raw_input().strip().split())

T = 720720
print sum(any(d % M == R for M, R in zip(m, r)) for d in xrange(T)) / float(T)