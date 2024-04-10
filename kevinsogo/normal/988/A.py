n, k = map(int, input().split())
a = list(map(int, input().split()))
found = set()
inds = []
for i in range(n):
    if a[i] not in found:
        found.add(a[i])
        inds.append(i + 1)
        if len(inds) == k:
            print('YES')
            print(*inds)
            break
else:
    print('NO')