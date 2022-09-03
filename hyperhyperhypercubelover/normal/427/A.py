input()
r = t = 0
for x in map(int, input().split()):
  if x < 0:
    if not t:
      r += 1
    else:
      t -= 1
  else:
    t += x
print(r)