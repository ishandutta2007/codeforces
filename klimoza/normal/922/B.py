n = int(input())
ans = 0
for i in range(1, n + 1):
    for j in range(i // 2, i + 1):
        d = i ^ j
        if not(d > j or d + j <= i):
            ans += 1
print(ans)