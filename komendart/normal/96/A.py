s = raw_input()
num = 1
for i in range(1, len(s)):
    if s[i] != s[i-1]:
        num = 0
    num += 1
    if num == 7:
        break
print ["NO", "YES"][num == 7]