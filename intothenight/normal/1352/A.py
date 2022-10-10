import sys

t = int(input())
for _ in range(t):
	n = str(input())
	cnt = 0
	for c in n:
		if c != '0':
			cnt += 1
	print(cnt)
	for i in range(len(n)):
		if n[i] != '0':
			print(n[i], end = "")
			for j in range(len(n) - i - 1):
				print(0, end = "")
			print("", end = " ")
	print()