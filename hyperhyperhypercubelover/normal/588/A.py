t = 123
r = 0
for _ in range(int(input())):
  a, b = map(int, input().split())
  t = min(t, b)
  r += a * t
print(r)