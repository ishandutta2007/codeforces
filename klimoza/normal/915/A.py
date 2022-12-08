n, k = map(int, input().split())
maxi = 0
a = list(map(int, input().split()))
for i in a:
    if k % i == 0:
        maxi = max(maxi, i)
print(k // maxi)