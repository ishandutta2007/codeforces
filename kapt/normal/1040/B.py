n, k = map(int, input().split())
print((n + 2 * k) // (2 * k + 1))
x = 0
arr = []
for i in range(n - k, 0, -(2 * k + 1)):
    x += 1
    arr.append(i)
if x != ((n + 2 * k) // (2 * k + 1)):
    print(*[i for i in range(1, n + 1, 2 * k + 1)])
    exit()
print(*arr[::-1])