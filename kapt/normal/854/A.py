n = int(input())
gcd = lambda a, b: a if b == 0 else gcd(b, a % b)
for a in range(n - 1, 0, -1):
    b = n - a
    if a < b and gcd(a, b) == 1:
        print(a, b)
        break