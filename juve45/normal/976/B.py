n, m, k = map(int, input().split())

if k <= n - 1:
	print(k + 1, 1)
	exit(0)

k -= n
m -= 1
l = k // m
c = k % m
if l % 2 == 1:
	c = m - 1 - c
l = n - l
print(l, c + 2)