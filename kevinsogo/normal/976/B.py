n, m, k = map(int, raw_input().split())
if k < n:
    i, j = k, 0
else:
    i, j = divmod(k - n, m - 1)
    j += 1
    if i % 2: j = m - j
    i = n - 1 - i
print i + 1, j + 1