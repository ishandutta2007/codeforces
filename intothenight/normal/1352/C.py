import sys

t = int(input())
for _ in range(t):
	n, k = [int(x) for x in input().split()]
	t = k // (n - 1) * n
	if k % (n - 1):
		print(t + k % (n - 1))
	else:
		print(t - 1)