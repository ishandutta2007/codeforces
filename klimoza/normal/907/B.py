a = []
for i in range(11):
    f = input()
    if i != 3 and i != 7:
        a.append(f[:3] + f[4:7] + f[8:])
x, y = map(int, input().split())
x1 = x % 3
y1 = y % 3
if x1 == 0:
    x1 = 3
if y1 == 0:
    y1 = 3
bl = False
for i in range(3 * (x1 - 1), 3 * x1):
    for j in range(3 * (y1 - 1), 3 * y1):
        if a[i][j] == ".":
            bl = True
            a[i] = a[i][:j] + "!" + a[i][j + 1:]
if bl:
    for i in range(9):
        s = ""
        for j in range(9):
            if j % 3 == 0 and j != 0:
                s += " "
            s += a[i][j]
        if i % 3 == 0 and i != 0:
            print()
        print(s)
else:
    for i in range(9):
        s = ""
        for j in range(9):
            if j % 3 == 0 and j != 0:
                s += " "
            if a[i][j] == ".":
                s += "!"
            else:
                s += a[i][j]
        if i % 3 == 0 and i != 0:
            print()
        print(s)