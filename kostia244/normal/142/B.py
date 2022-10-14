def li():
  return list(map(int, input().split(" ")))
n, m = li()
if n < m:
  t =n
  n = m
  m = t
if m == 1:
  print(n)
elif m == 2:
  print(2*(2*(n//4) + min(n%4, 2)))
else:
  print((n*m) - (n*m)//2)