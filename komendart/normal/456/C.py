def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    
    max_n = max(a)
    
    count = [0 for i in range(max_n + 1)]
    for i in a:
        count[i] += 1
    
    dp = [0 for i in range(max_n + 1)]
    dp[1] = count[1]
    for i in range(2, max_n + 1):
        dp[i] = max(dp[i - 1], i * count[i] + dp[i - 2])
    
    print(dp[max_n])


main()