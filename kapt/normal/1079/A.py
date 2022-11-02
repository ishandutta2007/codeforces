n, k = map(int, input().split())
arr = list(map(int, input().split()))
cnt = [0] * 100
for i in range(n):
    cnt[arr[i] - 1] += 1
ans = 0
b = 1
for i in range(100):
    b = max(b, (cnt[i] + k - 1) // k)
for i in range(100):
    if cnt[i] % (k * b):
        ans += k * b - cnt[i] % (k * b)
print(ans)