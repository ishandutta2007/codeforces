# import sys
# input = sys.stdin.readline
t = int(input())
out = []

for _ in range(t):
    n = int(input())
    pos = []
    for __ in range(n):
        pos.append(tuple(map(int, input().split())))
    pos.sort()

    currX = 0
    currY = 0
    s = ''
    works = True
    for x, y in pos:
        if currX > x:
            works = False
            break
        else:
            s += 'R' * (x - currX)
            currX = x
        if currY > y:
            works = False
            break
        else:
            s += 'U' * (y - currY)
            currY = y
    if works:
        out.append('YES')
        out.append(s)
    else:
        out.append('NO')
print('\n'.join(out))