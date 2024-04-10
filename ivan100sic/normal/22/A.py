input()
a = sorted(set(map(int, input().split())))
if len(a) == 1:
	print("NO")
else:
	print(a[1])