p, q = map(int,raw_input().strip().split())
n = input()
a = map(int,raw_input().strip().split())

def compile(i):
    if i + 1 == n:
        return a[i], 1
    p, q = compile(i + 1)
    return p * a[i] + q, p

P, Q = compile(0)

print "YES" if P * q == p * Q else "NO"