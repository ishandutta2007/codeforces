temp = input()
n = int(temp)

temp = []
a = []
temp = input().split()
for i in range(n):
    a.append(int(temp[i]))
mn = int(0)

for i in range(n):
    if (a[i] <= a[mn]):
        mn = i
ans = int(0)
while mn != n-1:
    # swap
    c = a[mn]
    a[mn] = a[mn+1]
    a[mn+1] = c
    mn = mn + 1
    ans = ans + 1
i = int(n-1)
mx = i
while (i>=0):
    if (a[i] >= a[mx]):
        mx = i
    i = i - 1
while mx != 0:
    # swap 2
    c = a[mx]
    a[mx] = a[mx-1]
    a[mx-1] = c
    mx = mx - 1
    ans = ans + 1
print(ans)