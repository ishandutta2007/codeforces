n = int(input())
s = input()
for d in range(1, n+1):
    if n % d == 0: s = s[:d][::-1] + s[d:]
print(s)