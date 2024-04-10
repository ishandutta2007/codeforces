n = int(input().strip())
ans = 0
pairs = list(map(int, input().split()))
curr_old = 10000000000
for i in range(n):
    if pairs[i] == 1:
        ans += 1
        if i - curr_old == 2:
            ans += 1
        curr_old = i
print(ans)