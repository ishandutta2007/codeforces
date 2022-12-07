n = int(input())
for i in range(n):
    print(('*' * (n // 2 - min(i, n - 1 - i))) + ('D' * min(1 + 2 * i, 2 * (n - i) - 1)) + ('*' * (n // 2 - min(i, n - 1 - i))))