n = int(input())
for i in range(n):
    t = int(input())
    if t % 3 == 0:
        print('YES')
    elif t % 3 == 1:
        if t >= 7:
            print('YES')
        else:
            print('NO')
    else:
        if t >= 14:
            print('YES')
        else:
            print('NO')