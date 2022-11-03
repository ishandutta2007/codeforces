n = int(input())
a = [int(input()) for i in range(n)]

for mask in range(2 ** n) :
    ans = 0
    cmask = mask
    for i in range(n) : 
        ans = ans + (a[i] if (cmask % 2 == 1) else -a[i])
        cmask = cmask // 2
    if (ans % 360 == 0) : 
        print('YES')
        exit(0)

print('NO')