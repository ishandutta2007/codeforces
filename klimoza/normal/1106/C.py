n = int(input())
a = list(map(int, input().split()))
a.sort()
ans = 0
for i in range(0, int(n / 2)):
    cur = a[i] + a[n - i - 1]
    if(n % 2 == 1 and i == ((n / 2) - 1)):
        cur += a[n / 2]
    ans += cur * cur
print(ans)