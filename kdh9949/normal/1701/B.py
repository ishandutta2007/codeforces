for _ in range(int(input())):
    n = int(input())
    print(2)
    for i in range(1, n + 1, 2):
        j = i
        while j <= n:
            print(j, end=' ')
            j *= 2
    print()