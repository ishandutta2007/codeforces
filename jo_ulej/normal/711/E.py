n, k = map(int, input().split())
if n <= 100 and k > (2 ** n):
    print(1, 1)
    exit(0)
MOD = 1000 * 1000 + 3
INV2 = (MOD + 1) // 2
def add(x, y):
    return (x + y) % MOD
def sub(x, y):
    rez = x - y
    rez %= MOD
    rez += MOD
    rez %= MOD
    return rez
def mult(x, y):
    return (x * y) % MOD
def binpow(x, y):
    if x == 1 or y == 0:
        return 1
    if x == 0:
        return 0
    rez = binpow(x, y//2)
    rez = mult(rez, rez)
    if y % 2 == 1:
        rez = mult(rez, x)
    return rez

A = n * k
B = n
temp = k - 1
while temp >= 2:
    B += temp // 2
    temp //= 2
G = min(A, B)
# print('G=', G)
m = binpow(2, n)
# print('m=', m)
P = 1
for i in range(k):
    P = mult(P, sub(m, i))
    if P == 0:
        break
P = mult(P, binpow(INV2, G))
Q = binpow(m, k)
Q = mult(Q, binpow(INV2, G))
P = sub(Q, P)
print(P, Q)