x, y = [int(i) for i in input().split()]

sign = lambda n: n // abs(n)

x1 = (abs(x) + abs(y)) * sign(x)
y1 = (abs(x) + abs(y)) * sign(y)

if x1 < 0:
    print(x1, 0, 0, y1)
else:
    print(0, y1, x1, 0)