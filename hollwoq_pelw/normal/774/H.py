n = int(input())
a = [0] + list(map(int, input().split()))
for i in range(n, 0, -1):
    for j in range(i + 1, n + 1):
        a[i] -= a[j] * (j - i + 1)
x = 'b'
for i in range(1, n + 1):
    for _ in range(a[i]):
        for __ in range(i):
            print(x, end = '')
        x = chr(ord(x) ^ 1)