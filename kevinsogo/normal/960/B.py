n, k1, k2 = map(int, raw_input().split())
a = map(int, raw_input().split())
b = map(int, raw_input().split())
k = k1 + k2
v = [abs(A - B) for A, B in zip(a, b)]
for it in xrange(k):
    i = max(xrange(len(v)), key=lambda i: v[i])
    v[i] = abs(v[i] - 1)
print sum(x**2 for x in v)