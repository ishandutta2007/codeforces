input()
r = -1
for x in map(int, input().split()):
  if r < 0:
    r = 0
    mx = mn = x
  if x > mx:
    r += 1
    mx = x
  if x < mn:
    r += 1
    mn = x
print(r)