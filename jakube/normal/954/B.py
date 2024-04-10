n = int(input())
s = input()

longest = 0
for i in range(1, n+1):
    if s[0:i] == s[i:2*i]:
        longest = i

if longest:
    print(n - longest + 1)
else:
    print(n)