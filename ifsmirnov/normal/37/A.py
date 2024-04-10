n = raw_input()
a = [int(i) for i in raw_input().split()]
b = {}
for i in a:
    if not i in b:
        b[i] = 0
    b[i] += 1

cmax = -1
for i in b:
    cmax = max(cmax, b[i])
print cmax, len(b)