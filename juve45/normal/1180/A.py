def sum(n):
	return n * (n + 1) // 2;


n = int(input())

print (sum (n) + sum(n - 1) + sum(n - 1) + sum(n - 2))