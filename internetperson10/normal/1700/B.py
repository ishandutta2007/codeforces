t = int(input())
for _ in range(t):
    n = int(input())
    x = int(input())
    y = 10**n + 1 - x
    if y >= 10**(n-1):
        print(y)
    else:
        print((10**(n+1) - 1) // 9 - x)