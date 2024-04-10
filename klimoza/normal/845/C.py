n = int(input())
t = [0] * n
t1 = -1
t2 = -1
ff = True
for i in range(n):
    a, b = map(int, input().split())
    t[i] = (a, b)
t.sort()
for i in range(n):
    bl = False
    if t[i][0] > t1:
        t1 = t[i][1]
        bl = True
    if not bl and t[i][0] > t2:
        t2 = t[i][1]
        bl = True
    if not bl:
        ff = False
        break
if ff:
    print("YES")
else:
    print("NO")