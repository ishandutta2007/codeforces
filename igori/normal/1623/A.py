for i in range(int(input())):
    n, m, xb, yb, xd, yd = map(int, input().split())
    a = xd - xb
    if a < 0:
        a = n - xd + n - xb
    b = yd - yb
    if b < 0:
        b = m - yd + m - yb
    print(min(a, b))