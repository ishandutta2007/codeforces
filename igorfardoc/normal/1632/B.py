for _ in range(int(input())):
	n = int(input())
	k = 1
	while 2 * k <= n - 1:
		k *= 2
	for i in range(k - 1, -1, -1):
		print(i, end=' ')
	for i in range(k, n):
		print(i, end=' ')
	print()