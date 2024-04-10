from itertools import count

def good(n, v):
    if v % 2 or v == 0: return False
    while v + v <= n: v += v
    return (n ^ v) < n

def reducemul(n, k=6):
    def muls():
        for e in count(1):
            for d in -1, 0, +1:
                yield (1 << e) + d
    for m in muls():
        a, b = n * m, n
        for it in range(k):
            a, b = a + b, a ^ b
            if good(n, b): return m

def solve(n):
    while n > 1:
        m = reducemul(n)

        a = 0
        p = n
        while m:
            if m & 1:
                if a: yield a, '+', p
                a += p
            yield p, '+', p
            p += p
            m >>= 1

        b = n
        while not good(n, b):
            yield a, '+', b
            yield a, '^', b
            a, b = a + b, a ^ b

        while b + b <= n:
            yield b, '+', b
            b += b

        yield n, '^', b
        n ^= b

    assert n == 1

sol = [*solve(int(input()))]
print(len(sol))
for line in sol: print(*line)