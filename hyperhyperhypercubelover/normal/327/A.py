n = int(input())
a = [0] + list(map(int, input().split()))
for i in range(1, n + 1):
  a[i] += a[i - 1]
r = 0
for i in range(0, n):
  for j in range(i + 1, n + 1):
    r = max(r, a[i] + a[n] - a[j] + (j - i - a[j] + a[i]))
print(r)