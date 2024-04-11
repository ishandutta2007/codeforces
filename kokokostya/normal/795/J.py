n, k = map(int, input().split())
s = input()
cur = s[0] == 'N'
mx = cur
for i in range(1, n):
    if (s[i] == 'N'):
        cur += 1
    else:
        cur = 0
    mx = max(mx, cur)
if (mx > k):
    print("NO")
    exit(0)
for i in range(k - 1, n):
    ch = 1
    for j in range (i - k + 1, i + 1):
        if (s[j] == 'Y'):
            ch = 0
    if (i > k - 1 and s[i - k] == 'N'):
        ch = 0
    if (i < n - 1 and s[i + 1] == 'N'):
        ch = 0
    if (ch):
        print("YES")
        exit(0)
print("NO")