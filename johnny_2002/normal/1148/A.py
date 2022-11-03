a, b, c = map(int, input().split())
d = min(a, b)
a = a - d
b = b - d
ans = 2 * (c + d) + min(a, 1) + min(b, 1)
print(ans)