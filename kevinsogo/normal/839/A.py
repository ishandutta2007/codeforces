n, k = map(int, raw_input().strip().split())
vs = map(int, raw_input().strip().split())

a = b = 0
for i, v in enumerate(vs):
    a += v
    d = min(8, a)
    a -= d
    b += d
    if b >= k:
        print i + 1
        break
else:
    print -1