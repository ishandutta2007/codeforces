n = int(input())
for i in range(100):
  if i * (i + 1) * (i + 2) <= n * 6:
    r = i
print(r)