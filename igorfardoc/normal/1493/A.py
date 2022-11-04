t = int(input())
for o in range(t):
    n, k = list(map(int, input().split()))
    res = []
    for i in range(k + 1, n + 1):
        res.append(str(i))
    niz = k // 2 - 1
    if k % 2 == 1:
        niz = k // 2
    for i in range(k - 1, niz, -1):
        res.append(str(i))
    print(len(res))
    print(' '.join(res))