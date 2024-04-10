def sq(arr):
    y1, x1 = arr[0][0], arr[0][1]
    xa, ya = x1, y1
    cnt = 0
    for i in range(2):
        yb, xb = arr[i + 1][0], arr[i + 1][1]
        cnt += (xb - xa) * (ya + yb) / 2
        xa, ya = xb, yb
    cnt += (x1 - xa) * (y1 + ya) / 2
    return cnt


def inm(points, x, y):
    f = True
    for i in range(4 - 1, -1, -1):
        a, b, c = points[i], points[i - 1], points[i - 2]
        if not((sq([a, b, c]) >= 0 and sq([a, b, (x, y)]) >= 0) or (sq([a, b, c]) <= 0 and sq([a, b, (x, y)]) <= 0)):
            f = False
            break
    return f


read = lambda: map(float, input().split())
n = 4
points1 = []
arr = list(map(int, input().split()))
for i in range(4):
    points1.append((arr[i * 2 + 1], arr[i * 2]))
points2 = []
arr = list(map(int, input().split()))
for i in range(4):
    points2.append((arr[i * 2 + 1], arr[i * 2]))
for i in range(-100, 101):
    for j in range(-100, 101):
        if inm(points1, i, j) and inm(points2, i, j):
            print('YES')
            exit()
print('NO')