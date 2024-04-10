n, m = map(int, input().split())

if n == 1:
    print(1)
else:
    print('{:9}'.format((n-1)/n * (m - 1) / (n*m - 1) + 1 / n))