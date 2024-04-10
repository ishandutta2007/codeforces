n, k = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0
for i in range(n):
    if arr[i] <= k:
        ans += 1
    else:
        break
for i in range(n - 1, -1, -1):
    if arr[i] <= k:
        ans += 1
    else:
        break
print(min(n, ans))