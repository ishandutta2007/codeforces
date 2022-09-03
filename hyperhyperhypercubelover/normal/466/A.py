n, m, a, b = map(int, input().split())
print(min(n * a, n // m * b + n % m * a, (n + m - 1) // m * b))