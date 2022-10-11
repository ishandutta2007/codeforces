from math import*
a = list(map(float, input().split()))
b = list(map(float, input().split()))
c = list(map(float, input().split()))
da = atan2(b[1] - a[1], b[0] - a[0]) - atan2(c[1] - a[1], c[0] - a[0])
db = atan2(a[1] - b[1], a[0] - b[0]) - atan2(c[1] - b[1], c[0] - b[0])
dc = atan2(b[1] - c[1], b[0] - c[0]) - atan2(a[1] - c[1], a[0] - c[0])
da = abs(da)
db = abs(db)
dc = abs(dc)
if(da > pi):
    da = 2 * pi - da
if(db > pi):
    db = 2 * pi - db
if(dc > pi):
    dc = 2 * pi - dc
bc = (c[0] - b[0])**2 + (c[1] - b[1])**2
for i in range(3, 101):
    x = pi / i
    f = 3 * [0]
    for j in range(1, i - 1):
        if abs(x * j - da) < 0.0001:
            f[0] = 1
        if abs(x * j - db) < 0.0001:
            f[1] = 1
        if abs(x * j - dc) < 0.0001:
            f[2] = 1
    if f == 3 * [1]:
        o = round(da / x) - 1
        t = i * [1]
        for j in range(1, i - 1):
            t[j] = t[j - 1] * cos(x) + cos(x * j)
        print(i * bc / t[o] / t[o] * cos(x) / sin(x) / 4)
        break