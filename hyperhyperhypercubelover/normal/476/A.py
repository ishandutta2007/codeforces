n, m = map(int, input().split())
r = -1
for i in range(n // 2 + 1):
  if not (n - i) % m:
    r = n - i
print(r)