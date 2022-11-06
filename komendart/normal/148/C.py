n, a, b = [int(i) for i in input().split()]

if n == 1:
    print(1)
elif 2**b + a > 50000 or b == 0 and a == n - 1:
    print(-1)
elif b == 0:
    print(1, 1, end=' ')
    last = 1
    for i in range(a):
        last += 1
        print(last)
    for i in range(n - a - 2):
        print(last)
else:
    last = 1
    print(1, end=' ')
    for i in range(b):
        last *= 2
        print(last, end=' ')
    for i in range(a):
        last += 1
        print(last, end=' ')
    for i in range(n - a - b - 1):
        print(last, end=' ')