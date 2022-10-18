px, py, vx, vy, a, b, c, d = map(int, input().split())

v = (vx**2 + vy**2)**.5

print('{} {}'.format(px + vx/v*b, py + vy/v*b))
print('{} {}'.format(px - vy/v*a/2, py + vx/v*a/2))
print('{} {}'.format(px - vy/v*c/2, py + vx/v*c/2))
print('{} {}'.format(px - vy/v*c/2 - vx/v*d, py + vx/v*c/2 - vy/v*d))
print('{} {}'.format(px + vy/v*c/2 - vx/v*d, py - vx/v*c/2 - vy/v*d))
print('{} {}'.format(px + vy/v*c/2, py - vx/v*c/2))
print('{} {}'.format(px + vy/v*a/2, py - vx/v*a/2))