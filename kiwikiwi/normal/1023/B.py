n, k = map(int, raw_input().split())

# k - x <= n

r = min((k - 1) / 2, n)
l = max(1, k - n)
print max(0, r - l + 1)