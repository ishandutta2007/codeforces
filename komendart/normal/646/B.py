s = input()
n = len(s)
for i in range(n):
    if i * 2 > n and s[:i] == s[-i:]:
        print("YES")
        print(s[:i])
        break
else:
    print("NO")