t = int(input())
for i in range(t):
    n = int(input())
    result = n * (n + 1) // 2
    j = 1
    while j <= n:
        result -= 2 * j
        j *= 2
    print(result)