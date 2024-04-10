r = lambda: input()
ri = lambda: int(r())
rr = lambda: map(int, r().split())
rl = lambda: list(rr())

n = ri()
arr = [rl() for i in range(n)]

a = set()
b = set()
for i in range(n):
    if arr[i][0] > 0:
        a.add((arr[i][0], arr[i][1]))
    else:
        b.add((arr[i][0], arr[i][1]))
        
a = sorted(list(a))
b = sorted(list(b), reverse = True)

L = min(len(a), len(b))
s = 0
for i in range(L + 1):
    if i == L:
        if len(b) > L:
            s += b[i][1]
        elif len(a) > L:
            s += a[i][1]
    else:
        s += a[i][1]
        s += b[i][1]

print(s)