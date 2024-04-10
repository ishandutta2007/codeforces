s = input()
i = 1
a = []
if (len(s) == 2):
    print(0)
    exit(0)
while i < len(s):
    a.append(int(ord(s[i])))
    i = i + 3
a.sort()
ans = 0
for i in range(len(a)):
    if i == 0 or a[i]!=a[i-1]:
        ans = ans + 1
print(ans)