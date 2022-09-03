n = int(input())
a = list(map(int, input().split()))
t = 0
for x in sorted(range(n), key = lambda t: a[t]):
	t = max(t + 1, a[x])
	a[x] = t
print(' '.join(map(str, a)))