n = int(input())
dp = [1, 2]
while dp[-2] + dp[-1] <= n:
    dp.append(dp[-2] + dp[-1])
print(len(dp) - 1)