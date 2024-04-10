n, pos, l, r = map(int, input().split())
if r == n and l == 1:
    print(0)
elif r == n:
    print(abs(pos - l) + 1)
elif l == 1:
    print(abs(r - pos) + 1)
else:
    s1 = abs(r - pos)
    s2 = abs(l - pos)
    print(min(s1, s2) + (r - l) + 2)