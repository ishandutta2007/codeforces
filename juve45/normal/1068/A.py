n, m, k, l = map(int, input().split())

if k + l > n:
    print(-1)
else:
    ans = (k + l + m - 1) // m
    if ans * m > n:
        ans = -1
    print(ans)