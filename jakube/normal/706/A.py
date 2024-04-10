a, b = map(int, input().split())
n = int(input())
d = 10**99
for _ in range(n):
    x, y, v = map(int, input().split())
    dist = ((x-a)**2 + (y-b)**2) ** .5
    ti = dist / float(v)
    d = min(d, ti)
print(d)