n, m = map(int, input().split())
for i in range(n + 1):
  if i * (i + 1) // 2 * 5 + m <= 240:
    r = i
print(r)