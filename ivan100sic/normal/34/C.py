a = list(sorted(set(map(int, input().split(',')))))
l = -2
r = -2
s = []
for x in a:
    if r >= 0 and x == r + 1:
        r = x
    elif r >= 0:
        if l < r:
            s += [str(l)+'-'+str(r)]
        else:
            s += [str(l)]
        l = x
        r = x
    else:
        l = x
        r = x

if r >= 0:
    if l < r:
        s += [str(l)+'-'+str(r)]
    else:
        s += [str(l)]
    l = x
    r = x

print(','.join(s))