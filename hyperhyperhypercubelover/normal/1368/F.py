import sys
n = int(input())
k = min(range(1, n + 1), key = lambda i: (n - 1) // i + i)
d = { i for i in range(1, n + 1) if i % k }
a = set()
while d:
  t = list(d - a)[:k]
  print(len(t), *t, flush = True)
  a |= set(t)
  if a == d: break
  i = int(input())
  a -= set(range(i, min(i + len(t), n + 1)))
  a -= set(range(1, i + len(t) - n))
print(0)