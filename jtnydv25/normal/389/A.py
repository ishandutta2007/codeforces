from fractions import gcd
n, A = input(), map(int, raw_input().split())

x = 0
for i in A: x = gcd(x, i)
print x * n