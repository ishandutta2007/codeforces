n = int(input())
arr = list(map(int, input().split()))
x = max(arr)
now = 0
ans = 1
for i in range(n):
    if arr[i] == x:
        now += 1
    else:
        now = 0
    if now > ans:
        ans = now;
print(ans)