n, a, b, c = map(int, input().split())
d = [-987654321] * (n + 1)
d[0] = 0
for i in range(1, n + 1):
  if i >= a:
    d[i] = max(d[i], d[i - a] + 1)
  if i >= b:
    d[i] = max(d[i], d[i - b] + 1)
  if i >= c:
    d[i] = max(d[i], d[i - c] + 1)
print(d[n])