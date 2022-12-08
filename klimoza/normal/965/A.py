k, n, s, p = map(int, input().split())
t = 0
if n % s == 0:
    t = n // s
else:
    t = n // s + 1
t = t * k
if t % p == 0:
    print(t // p)
else:
    print(t // p + 1)