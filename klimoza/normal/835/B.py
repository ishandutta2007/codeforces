a = [0] * 10
suma = 0
k = int(input())
n = input()
for i in n:
    suma += int(i)
    a[int(i)] += 1
suma = k - suma
if suma <= 0:
    print(0)
else:
    j = 0
    h = 0
    t = 0
    while h < suma:
        r = a[j] * (9 - j)
        h += r
        t += a[j]
        j += 1
    j -= 1
    while h >= suma:
        h -= (9 - j)
        t -= 1
    if h == suma:
        print(t)
    else:
        print(t + 1)