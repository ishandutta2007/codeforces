n = int(input())
a = list(map(int, input().split()))
maxi = 100000000
ans = -1
for t in range(1, 101):
    cur = 0
    for i in a:
        cur += min(abs(i - t), abs(i - t - 1), abs(i - t + 1))
    if cur < maxi:
        maxi = cur
        ans = t
print(ans, maxi)