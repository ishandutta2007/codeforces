from math import hypot
px, py, vx, vy, a, b, c, d = map(float, raw_input().split())
x, y = 0, b; print px + (vy*x + vx*y) / hypot(vx, vy), py + (vy*y - vx*x) / hypot(vx, vy)
x, y = -a/2, 0; print px + (vy*x + vx*y) / hypot(vx, vy), py + (vy*y - vx*x) / hypot(vx, vy)
x, y = -c/2, 0; print px + (vy*x + vx*y) / hypot(vx, vy), py + (vy*y - vx*x) / hypot(vx, vy)
x, y = -c/2, -d; print px + (vy*x + vx*y) / hypot(vx, vy), py + (vy*y - vx*x) / hypot(vx, vy)
x, y = c/2, -d; print px + (vy*x + vx*y) / hypot(vx, vy), py + (vy*y - vx*x) / hypot(vx, vy)
x, y = c/2, 0; print px + (vy*x + vx*y) / hypot(vx, vy), py + (vy*y - vx*x) / hypot(vx, vy)
x, y = a/2, 0; print px + (vy*x + vx*y) / hypot(vx, vy), py + (vy*y - vx*x) / hypot(vx, vy)