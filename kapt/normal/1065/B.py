n, m = map(int, input().split())
print(max(n - 2 * m, 0), end=' ')
l = -1
r = n + 1
while r - l > 1:
    med = (l + r) // 2
    if 2 * m > med * (med - 1):
        l = med
    else:
        r = med
print(n - r)