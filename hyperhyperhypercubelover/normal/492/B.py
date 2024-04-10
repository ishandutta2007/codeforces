n, m = map(int, input().split())
a = sorted(list(map(int, input().split())))
r = max(a[0], m - a[-1]) * 2
for i in range(1, n):
  r = max(r, a[i] - a[i - 1])
print(r / 2)