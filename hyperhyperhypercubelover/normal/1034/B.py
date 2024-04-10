n, m = map(int, input().split())
if n > m:
  n, m = m, n
if n == 1:
  print(m // 6 + (m + 1) // 6 + (m + 2) // 6 << 1)
elif n == 2:
  print(0 if m == 2 else 4 if m == 3 else 12 if m == 7 else n * m)
else:
  print(n * m >> 1 << 1)