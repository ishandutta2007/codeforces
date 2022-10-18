x1, y1, x2, y2 = map(int, input().split())

t = (y2 - y1) // 2 + 1
r = (x2 - x1) + 1
#print(t, r)
print((r+1)//2 * t + r//2*(t-1))