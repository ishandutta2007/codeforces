n, m = map(int, input().split())
t = 10 ** (n - 1)
while t % m:
  t += 1
print(t if t < 10 ** n else -1)