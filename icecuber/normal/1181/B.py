n = int(input())
s = input()
l,r = n//2, (n+1)//2
while s[l] == '0': l -= 1
while r < n and s[r] == '0': r += 1
ans = int(s)
if l > 0:
    ans = int(s[:l])+int(s[l:])
if r < n:
    ans = min(ans, int(s[:r])+int(s[r:]))
print(ans)