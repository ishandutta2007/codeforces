input()
a=list(sorted(set(map(int, input().split()))))
for i in range(len(a)-2):
	if a[i+2] - a[i] == 2:
		print("YES")
		exit()
print("NO")