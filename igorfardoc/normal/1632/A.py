for _ in range(int(input())):
	n = int(input())
	s = input()
	if n > 2 or s in ["11", "00"]:
		print("NO")
	else:
		print("YES")