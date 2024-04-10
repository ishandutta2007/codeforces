import sys

t = int(input())
for _ in range(t):
	n, k = [int(x) for x in input().split()]
	if ((k % 2 == 0 and (n % 2 == 1 or k > n)) or (k % 2 == 1 and ((n % 2 == 1 and k > n) or (n % 2 == 0 and 2 * k > n)))):
		print("NO")
	else:
		print("YES")
		if n % 2 == 0:
			if k % 2 == 0:
				for _ in range(k - 1):
					print(1, end = " ")
				print(n - (k - 1))
			else:
				for _ in range(k - 1):
					print(2, end = " ")
				print(n - 2 * (k - 1))
		else:
			for _ in range(k - 1):
				print(1, end = " ")
			print(n - (k - 1))