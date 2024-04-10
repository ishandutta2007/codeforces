n, a, b = map(int, input().split())
arr = list(map(int, input().split()))
x = [a, b]
ans = 0
for i in range(n // 2):
    if arr[i] == 2 and arr[n - i - 1] == 2:
        ans += min(x) * 2
    elif arr[i] == 2:
        ans += x[arr[n - i - 1]]
    elif arr[n - i - 1] == 2:
        ans += x[arr[i]]
    elif arr[i] != arr[n - i - 1]:
        print(-1)
        exit()
if n % 2 == 1 and arr[n // 2] == 2:
    ans += min(x)
print(ans)