x, y = map(int, raw_input().strip().split())
c = raw_input()

dx, dy = 0, 0
for a in c:
  if a == 'U':
    dy += 1
  if a == 'D':
    dy -= 1
  if a == 'L':
    dx -= 1
  if a == 'R':
    dx += 1

def good(n, d):
  if d < 0:
    n = -n
    d = -d
  return n % d == 0 and n >= 0
def subok(cx, cy):
  if dx == dy == 0:
    return x == cx and y == cy
  if dx == 0:
    return x == cx and good(y - cy, dy)
  if dy == 0:
    return y == cy and good(x - cx, dx)
  return good(x - cx, dx) and good(y - cy, dy) and (x - cx) / dx == (y - cy) / dy

cx, cy = 0, 0
ans = subok(cx, cy)
for a in c:
  if ans:
    break
  if a == 'U':
    cy += 1
  if a == 'D':
    cy -= 1
  if a == 'L':
    cx -= 1
  if a == 'R':
    cx += 1
  ans = subok(cx, cy)

print 'Yes' if ans else 'No'