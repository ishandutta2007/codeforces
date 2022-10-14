def li():
  return list(map(int, input().split(" ")))
for _ in range(int(input())):
  a, b=li()
  if b != 0 and a != 0:
    s = (max(0, a-4*b) + a)/2
    s*=min((a/4), b)
    ans = 1/2 + s/(2*a*b)
    print("{:.8f}".format(ans))
  elif b == 0:
    print(1)
  else:
    print(0.5)