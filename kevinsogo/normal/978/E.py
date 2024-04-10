n, w = map(int, input().split())
cr = mx = mn = 0
for v in map(int, input().split()):
    cr += v
    mn = min(mn, cr)
    mx = max(mx, cr)
print(max(0, w - mx + mn + 1))