def f(c):
    v1 = c > '@'
    v2 = c < '['
    v3 = c > '`'
    v4 = c < '{'
    v5 = int(v1 and v2)
    v6 = int(v3 and v4)
    if c in '.0123456789':
        v7 = -1
    else:
        v7 = 'abcdefghijklmnopqrstuvwxyz'.index(c.lower()) + 1
    v8 = v5 * v7
    v9 = v6 * v7
    return v8 - v9

line = input()
res = 0
for c in line:
    res += f(c)
print(res)