x, y, m = map(int,raw_input().strip().split())

turns = 0
poss = True
x, y = min(x, y), max(x, y)
while y < m:
  if y <= 0:
    poss = False
    break
  if x <= 0:
    #x + qy > 0

    #qy > -x
    #q > (-x) / y
    q = (-x) / y + 1
    x += q * y
    turns += q
    #while x <= 0:
      #x += y
      #turns += 1
  else:
      x += y
      turns += 1
  x, y = min(x, y), max(x, y)
print turns if poss else -1