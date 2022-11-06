from decimal import Decimal

n, *x = [int(i) for i in input().split()]
m, *y = [int(i) for i in input().split()]
k, *z = [int(i) for i in input().split()]
A, B = [int(i) for i in input().split()]

r1 = max(x)
p1 = max(y)
p2 = min(z)

r2 = Decimal(r1) / (Decimal(A * p2) / Decimal(B * p1) + Decimal(1)).sqrt()

print(r2)