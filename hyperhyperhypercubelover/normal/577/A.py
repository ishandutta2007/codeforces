n, m = map(int, input().split())
r = 0
for i in range(1, n + 1):
  if not m % i and n * i >= m:
    r += 1
print(r)