n, a, b = map(int, input().split())

if n > a * b:
    print(-1)
else:
    for i in range(a):
        s = []
        for j in range(b):
            s.append(n)
            if n:
                n -= 1
        if i % 2 == 0:
            s = s[::-1]
        print(' '.join(map(str, s)))