n = int(input())
f = list(map(int, input().split()))
ans = 1
now = -1
for i in range(n):
    if (f[i]):
        if (now != -1):
            ans = ans * (i - now)
        now = i
if (now == -1):
    ans = 0
print(ans)