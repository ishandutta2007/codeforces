n = int(input())
r = 1
for i in range(1, n):
  r = r * (n + i - 1) // i
print(r)