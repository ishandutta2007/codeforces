MOD = 10**9+7

n = int(raw_input())
s = map(int, raw_input().split())

fct = [1]*200005
for i in xrange(1,200005):
    fct[i] = fct[i-1]*i % MOD

k = 0
while (n-k) % 4 != 1:
    k += 1

op = 1
for _ in xrange(k):
    t = []
    for j in xrange(len(s)-1):
        t.append((s[j] + op * s[j+1]) % MOD)
        op = MOD - op
    s = t
n -= k

def chs(a, b):
    return fct[a] * pow(fct[b] * fct[a-b], MOD-2, MOD) % MOD

res = 0
for i in xrange(0,n,2):
    res += chs(n/2, i/2) * s[i]
print res % MOD