def solve(n, st, k):
    MOD = int(1e9 + 7)
    dp = [0] * (n + 1)
    prefix_sum = [0] * (n + 1)
    dp[st] = 1
    for times in range(k):
        prefix_sum[0] = 0
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + dp[i]
            if prefix_sum[i] >= MOD: prefix_sum[i] -= MOD
        for i in range(1, n + 1):
            dp[i] = prefix_sum[n] - dp[i] - prefix_sum[i >> 1]
            while dp[i] < 0: dp[i] += MOD
            while dp[i] >= MOD: dp[i] -= MOD
    return sum(dp) % MOD
    

def main():
    n, a, b, k = [int(i) for i in input().split()]
    if a > b:
        print(solve(n - b, a - b, k))
    else:
        print(solve(b - 1, b - a, k))
    
main()