h1, a1, c1 = map(int, input().split())
h2, a2 = map(int, input().split())
a = []
t = 0
while h1 > 0 and h2 > 0:
    t += 1
    if h1 > a2 or h2 <= a1:
        h2 -= a1
        a.append('STRIKE')
    else:
        h1 += c1
        a.append('HEAL')
    h1 -= a2
print(t)
for i in range(len(a)):
    print(a[i])