a = b = 1
p, s = [0, 0], [0, 0]
for i in range(int(input())):
    p.append(int(input()))
    while p[-1] - p[a] > 89: a += 1
    while p[-1] - p[b] > 1439: b += 1
    s.append(min(s[-1] + 20, s[a - 1] + 50, s[b - 1] + 120))
print(' '.join(str(u - v) for u, v in zip(s[2:], s[1:])))