a = [int(i) for i in input().split()]
ans = sum(a)
for i in range(5):
    for j in range(i + 1, 5):
        for k in range(j + 1, 5):
            if a[i] == a[j] == a[k]:
                ans = min(ans, sum(a) - a[i] * 3)
        if a[i] == a[j]:
            ans = min(ans, sum(a) - a[i] * 2)
print(ans)