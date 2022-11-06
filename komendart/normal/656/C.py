s = input()
ans = 0
for c in s:
    ind = ord(c)
    if 'a' <= c <= 'z':
        ans -= ind - ord('a') + 1
    elif 'A' <= c <= 'Z':
        ans += ind - ord('A') + 1
print(ans)