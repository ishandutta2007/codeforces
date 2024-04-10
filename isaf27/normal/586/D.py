
t = int(input())
for kek in range(t):
    n, k = [int(i) for i in input().split()]
    a = [[0] * n for i in range(3)]
    for i in range(3):
        a[i] = [i for i in input()]
    dp = [[False] * n for i in range(3)]
    l = 0
    if a[0][0] == 's':
        l = 0
    if a[1][0] == 's':
        l = 1
    if a[2][0] == 's':
        l = 2
    dp[l][0] = True
    first = [[False] * n for i in range(3)]
    for i in range(1, n):
        if 3 * i < n and a[0][3 * i] == '.' and a[0][3 * i - 2] == '.':
            if (dp[0][i - 1] or first[0][i - 1]) or (a[1][3 * i - 2] == '.' and dp[1][i - 1]):
                dp[0][i] = True
        elif 3 * i >= n > 3 * i - 2:
            if (dp[0][i - 1] and a[0][3 * i - 2] == '.') or (dp[1][i - 1] and a[1][3 * i - 2] == '.'):
                dp[0][i] = True
        elif 3 * i >= n and (dp[0][i - 1] or dp[1][i - 1]):
            dp[0][i] = True
        if 3 * i < n and a[1][3 * i] == '.' and a[1][3 * i - 2] == '.':
            if (dp[1][i - 1] or first[1][i - 1]) or (a[0][3 * i - 2] == '.' and dp[0][i - 1]) or (a[2][3 * i - 2] == '.' and dp[2][i - 1]):
                dp[1][i] = True
        elif 3 * i >= n > 3 * i - 2:
            if (dp[0][i - 1] and a[0][3 * i - 2] == '.') or (dp[1][i - 1] and a[1][3 * i - 2] == '.') or (dp[2][i - 1] and a[2][3 * i - 2] == '.'):
                dp[1][i] = True
        elif 3 * i >= n and (dp[0][i - 1] or dp[1][i - 1] or dp[2][i - 1]):
            dp[1][i] = True
        if 3 * i < n and a[2][3 * i] == '.' and a[2][3 * i - 2] == '.':
            if (dp[2][i - 1] or first[2][i - 1]) or (a[1][3 * i - 2] == '.' and dp[1][i - 1]):
                dp[2][i] = True
        elif 3 * i >= n > 3 * i - 2:
            if (dp[2][i - 1] and a[2][3 * i - 2] == '.') or (dp[1][i - 1] and a[1][3 * i - 2] == '.'):
                dp[2][i] = True
        elif 3 * i >= n and (dp[1][i - 1] or dp[2][i - 1]):
            dp[2][i] = True
    #for i in range(3):
    #    print(dp[i])
    if max(dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]):
        print('YES')
    else:
        print('NO')