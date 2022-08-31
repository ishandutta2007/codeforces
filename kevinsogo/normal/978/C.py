n, m = map(int, input().split())
c = [0] 
for v in map(int, input().split()): c.append(c[-1] + v)
for v in map(int, input().split()):
    l, r = 0, len(c)
    while r - l > 1:
        m = l + r >> 1
        if c[m] < v:
            l = m
        else:
            r = m
    print(r, v - c[l])