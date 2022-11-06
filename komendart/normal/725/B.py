s = input()
n = int(s[:-1])
s = s[-1]

n -= 1
ans = n // 4 * 16 + n % 2 * 7

for i in "fedabc":
    ans += 1
    if s == i: break

print(ans)