def li():
  return set(map(int, input().split(" ")))
def sm(l, r):
  return (l+r) * ((r-l+2)//2)//2
def do(n):
  if(n <= 0):
    return 0
  l = r = 0
  pw = c = 1
  while(n >= pw):
    if c:
      l += pw
    else:
      r += pw
    n-=pw
    pw*=2
    c = 1-c
  if n > 0:
    if c:
      l += n
    else:
      r += n
  return sm(2, 2*r) + sm(1, 2*l-1)

a,b = input().split(" ")
a = int(a)
b = int(b)

print((do(b)-do(a-1))%1000000007)