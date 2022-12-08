n = int(input())
a = list(map(int, input().split()))
a.sort()
t = 1
maxi = 1
for i in range(1, len(a)):
    if a[i] == a[i - 1]:
        t += 1
    else:
        maxi = max(maxi, t)
        t = 1
maxi = max(maxi, t)
print(maxi)