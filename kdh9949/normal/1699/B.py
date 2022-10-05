t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    for i in range(n):
        for j in range(m):
            print((i + j + i // 2 + j // 2) % 2, end=' ')
        print()