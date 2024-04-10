n, k = map(int, input().split())
s = input()
a = [0 for i in range(26)]
cnt = 1
for i in range(1, n):
    if s[i] == s[i - 1]:
        cnt += 1
    else:
        a[ord(s[i - 1]) - ord('a')] += (cnt // k)
        cnt = 1
a[ord(s[n - 1]) - ord('a')] += (cnt // k)
ans = 0
for i in a:
    ans = max(ans, i)
print(ans)