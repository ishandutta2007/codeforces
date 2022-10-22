n = int(input())
q = []
for i in range(n):
    cmd, x = input().split()
    q.append((1 if cmd == 'win' else -1, int(x)))

lastsell = [n]*2001
dp = [0]*(n+1)
for i in range(n-1,-1,-1):
    dp[i] = dp[i+1]
    if q[i][0] == -1:
        lastsell[q[i][1]] = i
    else:
        l = lastsell[q[i][1]]
        if l < n:
            dp[i] = max(dp[i], dp[l]+(1<<q[i][1]))
print(dp[0])