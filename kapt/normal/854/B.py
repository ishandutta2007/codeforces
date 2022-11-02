n, k = map(int, input().split())
if k == 0 or k == n:
    print(0, end=' ')
else:
    print(1, end=' ')
if 3 * k <= n:
    print(2 * k)
else:
    print(n - k)