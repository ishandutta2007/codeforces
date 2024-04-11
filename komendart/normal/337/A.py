n, m = [int(i) for i in input().split()]
f = sorted(int(i) for i in input().split())

result = 100000
for i in range(m - n + 1):
    result = min(result, f[i + n - 1] - f[i])

print(result)