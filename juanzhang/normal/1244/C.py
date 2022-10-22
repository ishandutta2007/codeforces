x = 0
y = 0

def exgcd(a, b) :
  global x, y
  if (b == 0) :
    x = 1
    y = 0
    return a
  g = exgcd(b, a % b)
  t = x
  x = y
  y = t - a // b * y;
  return g

def calc(w, d, p) :
  global x, y
  g = exgcd(w, d)
  if (p % g) :
    return -1
  x *= p // g
  d //= g
  return (x % d + d) % d

n, p, w, d = map(int, input().split())

X = calc(w, d, p)
Y = calc(d, w, p)

if (X == -1) :
  print(-1)
else :
  y1 = (p - X * w) // d
  x2 = (p - Y * d) // w
  if (y1 >= 0 and X + y1 <= n) :
    print( X , y1 , n - X - y1 )
  else :
    if (x2 >= 0 and x2 + Y <= n) :
      print( x2 , Y , n - x2 - Y )
    else :
      print(-1)