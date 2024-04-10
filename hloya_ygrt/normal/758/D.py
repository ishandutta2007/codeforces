n = int(input())
s = input()

if s == '0':
    print(0)
    exit(0)

def dig(c):
    return ord(c) - ord('0')

def ind(i, cnt, len):
    return i + cnt * 65 + len * 65 * 65

dp = [int(10 ** 71)] * 70 * 70 * 70

dp[ind(0, 0, 1)] = 0

m = len(s)

for i in range(m):
    for cnt in range(0, 64):
        for len in range(1, 64):
            if dp[ind(i, cnt, len)] == int(10 ** 71):
                continue
            #print(i, cnt, len, dp[ind(i, cnt, len)])
            curDp = dp[ind(i, cnt, len)]
            # continue this
            if i != m - 1:
                dp[ind(i + 1, cnt, len + 1)] = min(dp[ind(i + 1, cnt, len + 1)], curDp)

            #start new
            #if i == m - 1:
            curKekNum = int(s[i - len + 1:i + 1])

            bad = False
            if s[i - len + 1] == '0' and len != 1:
                bad = True

            if bad == False and curKekNum < n:
                newDp = curDp * n + curKekNum
                dp[ind(i + 1, cnt + 1, 1)] = min(dp[ind(i + 1, cnt + 1, 1)], newDp)

ans = int(10 ** 71)
for cnt in range(1, 70):
    ans = min(ans, dp[ind(m, cnt, 1)])
print(ans)