import math

n = int(input())
c = 1
#print(c)
fl = False
a = []
while c <= 8 * n:
    c *= 2
    #print(D)
    #print(c)
    D = (c - 3) * (c - 3) + 8 * n
    x = int(math.sqrt(D))
    #print(x, D, (c + 1) * (c + 1))
    for i in range(-5, 5):
        if(x + i < 0): continue
        #print(x + i, (x + i) * (x + i))
        if((x + i) * (x + i) == D):
            x = x + i
    if(x * x != D):
        continue
    y = -(c - 3) + x
    #print(c, y, D)
    if(y % 2 == 1):
        continue
    y //= 2
    if(y % 2 == 0):
        continue
    k = c // 2 * y
    fl = True
    a.append(k)
a.sort()
for i in a:
    print(i)
if not fl:
    print(-1)