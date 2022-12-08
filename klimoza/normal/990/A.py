n, m, a, b = map(int, input().split())
t1 = n % m
t2 = m - t1
t1 *= b
t2 *= a
print(min(t1, t2))