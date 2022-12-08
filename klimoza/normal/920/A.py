t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    cont = 0
    r = 0
    b = [0 for i in range(n)]
    while cont < n:
        r += 1
        for i in a:
            if b[max(0, i - r)] == 0:
                cont += 1
                b[max(0, i - r)] = 1
            if b[min(n - 1, i + r - 2)] == 0:
                cont += 1
                b[min(n - 1, i + r - 2)] = 1
    print(r)