n, k = map(int, input().split())
if n == k or k == 0:
    print(0, 0)
else:
    if n % 3 == 0:
        t = n // 3
        if k <= t:
            print(1, k * 2)
        else:
            print(1, t * 3 - k)
    elif n % 3 == 1:
        t = n // 3
        if k <= t:
            print(1, k * 2)
        else:
            print(1, t * 3 - k + 1)
    else:
        t = n // 3
        if k <= t:
            print(1, k * 2)
        else:
            print(1, t * 3 - k + 2)