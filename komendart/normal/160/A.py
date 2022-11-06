n = int(raw_input())
coins = sorted((int(i) for i in raw_input().split()), reverse = True)
sum1 = sum(coins)
sum2 = 0
i = 0
while sum1 >= sum2:
    sum1 -= coins[i]
    sum2 += coins[i]
    i += 1
print i