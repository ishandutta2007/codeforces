for _ in range(int(input())):
    n = int(input())
    l, r = [0] * n, [0] * n
    for i in range(n):
        l[i], r[i] = map(int, input().split())
    ans = [0] * n
    for i in range(n):
        for j in range(n):
            if l[i] == l[j] and r[i] < r[j] and r[i] + 1 > ans[j]:
                ans[j] = r[i] + 1
    for i in range(n):
        if ans[i] == 0:
            ans[i] = l[i]
    for i in range(n):
        print(l[i], r[i], ans[i])
    print()