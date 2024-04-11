def check(k):
    n1 = k*p - x
    n2 = k*q - y
    assert(n1 >= 0)
    return n1 <= n2

t = int(input())
for _ in range(t):
  [x, y, p, q] = list(map(int, input().split(" ")))
  if p == 0 and x > 0:
      print(-1)
      continue
  if p == 0 and x == 0:
      print(0)
      continue
  st = max((x+p-1)//p, (y+q-1)//q)
  a = st-1
  b = 10**18
  while(b - a > 1):
    m = (a+b)//2
    if check(m):
        b = m
    else:
        a = m
  res = -1
  if b != 1e18:
    res = b*q - y
  print(res)