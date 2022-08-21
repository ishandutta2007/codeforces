n, m = map(int, input().split())
a = list(map(int, input().split()))
s = sum(a)
x = [[] for i in range(m)]
for i in range(n): x[a[i] % m].append(i)
j = 0
for i in range(m):
    while len(x[i]) > n // m:
        while j < i or len(x[j % m]) >= n // m: j += 1
        k = x[i].pop()
        a[k] += (j - i) % m
        x[j % m].append(k)
print(sum(a) - s)
print(*a)