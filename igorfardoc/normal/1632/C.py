for _ in range(int(input())):
    a, b = map(int, input().split())
    ans = b - a
    for a1 in range(a, b):
        b1 = 0
        for i in range(21, -1, -1):
            if (b >> i) & 1:
                b1 ^= (1 << i)
            else:
                if (a1 >> i) & 1:
                    b1 ^= (1 << i)
                    break
        ans = min(ans, a1 - a - b + (a1 | b1) + 1);
    print(ans)