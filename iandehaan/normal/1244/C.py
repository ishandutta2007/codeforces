n, p, w, d = map(int, input().split())
found = False
x = -1
y = -1
for draws in range(w):
    if p - draws*d < 0:
        continue 
    if (p-draws*d)%w != 0:
        continue
    if (p-draws*d)//w + draws > n:
        continue
    found = True
    x = (p-draws*d)//w
    y = draws
if found:
    print(x, y, n-x-y)
else:
    print(-1)