n = int(input())
a = [int(i) for i in input().split()]
s = sum(a) * 2 // n
used = [False] * n
for i in range(n):
    if used[i]: continue
    used[i] = True
    for j in range(n):
        if used[j]: continue
        if a[i] + a[j] == s:
            print(i + 1, j + 1)
            used[j] = True
            break