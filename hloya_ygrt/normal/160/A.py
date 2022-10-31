def _sum(a):
    ans = 0
    for i in a:
        ans = ans + int(i)
    return ans
n = int(input())
a = []
b = []
b = input().split()

for j in b:
    a.append(int(j))
a.sort()
a.reverse()

ls = 0
rs = _sum(a)
i = 0

while i < n and rs >= ls:
    ls += int(a[i])
    rs -= int(a[i])
    i = i + 1

print (i)