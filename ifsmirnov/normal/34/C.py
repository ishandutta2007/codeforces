a = [int(i) for i in raw_input().split(',')]
b = {}
for i in a:
    b[i] = 1
c = [i for i in b]
c.sort()
c.append(100000000)

ans = ''
last = -1
r = l = 0
for i in c:
    if i > last + 1:
        if (r < l):
            ans += str(r) + "-" + str(l) + ","
        else:
            ans += str(r) + ","
        r = last = i
    else:
        l = last = i
ans = ans[2:-1]

print ans