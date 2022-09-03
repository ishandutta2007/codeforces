n, m = map(int, input().split())
t = r = 0
for x in map(int, input().split()):
  x -= 1
  r += (x - t) % n
  t = x
print(r)