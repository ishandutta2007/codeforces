n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
mina = min(a)
minb = min(b)
a.sort()
minc = 0
for i in a:
    if i in b:
        minc = i
        break
if minc != 0:
    print(minc)
elif mina > minb:
    print(str(minb) + str(mina))
else:
    print(str(mina) + str(minb))