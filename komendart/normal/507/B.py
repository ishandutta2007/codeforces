r, x, y, x2, y2 = [int(i) for i in input().split()]

x = abs(x - x2)
y = abs(y - y2)

n = 0
while (2 * r * n) ** 2 < x * x + y * y:
    n += 1

print(n)