gap = 300
m = 1 << 15
isp = [False]*2 + [True]*(m - 1)
ps = []
for i in range(2, m + 1):
    if isp[i]:
        ps.append(i)
        for j in range(i * i, m + 1, i):
            isp[j] = False

n = int(input())
assert n % 2
if n >= m:
    low = n - gap
    ispg = [True]*(gap + 1)
    for p in ps:
        for i in range((low - 1) // p + 1, n // p + 1):
            ispg[i * p - low] = False

def is_prime(k):
    return isp[k] if k <= m else ispg[k - low]

p = n
while not is_prime(p): p -= 2
s = [p]
if p != n:
    if n - p == 2:
        s += [n - p]
    else:
        q = 2
        while not (is_prime(q) and is_prime(n - p - q)): q += 1
        s += [q, n - p - q]

print(len(s))
print(*s)