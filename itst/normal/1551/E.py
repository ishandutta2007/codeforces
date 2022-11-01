NUM = int(input())
for T in range(0,NUM):
    N , K = map(int,input().split())
    numlist = list(map(int,input().split()))
    for i in range(0 , N) : numlist[i] -= i + 1;
    dp = []
    ans = 10**10
    for i in range(0 , N):
        mx = 1
        for j in range(0 , i):
            if numlist[j] >= numlist[i] and numlist[j] - numlist[i] < i - j: mx = max(mx , dp[j] + 1)
        if numlist[i] > 0: mx = -N
        dp.append(mx)
        if mx == K: ans = min(ans , -numlist[i])
    if ans == 10**10: print(-1)
    else: print(ans)