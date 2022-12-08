n, k = map(int, input().split())
a = list(map(int, input().split()))
t = 0
ost = 0
i = 0
f = 0
while t < k and i < n:
    if ost >= 8:
        ost -= 8
        t += 8
        ost += a[i]
    else:
        t += ost
        f = 8 - ost
        if a[i] > f:
            t += f
            ost = a[i] - f
        else:
            t += a[i]
            ost = 0
    i += 1
if t < k:
    print(-1)
else:
    print(i)