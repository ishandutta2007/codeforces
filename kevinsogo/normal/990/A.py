n, m, a, b = map(int, raw_input().split())
print min((m - 1 - (n+m-1) % m) * a, (n % m) * b)