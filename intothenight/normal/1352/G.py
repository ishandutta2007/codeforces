t = int(input())
for _ in range(t):
	n = int(input())
	if n <= 3:
		print(-1)
	else:
		if n % 4 == 3:
			print(n, end = " ")
		if n % 4:
			print(n // 4 * 4 + 1, end = " ")
		for t in [3, 1, 4, 2]:
			for i in range(n // 4):
				if t <= 2:
					print(4 * i + t, end = " ")
				else:
					print(4 * (n // 4 - 1 - i) + t, end = " ")
		if n % 4 >= 2:
			print(n // 4 * 4 + 2, end = " ")
		print()


"""

"""