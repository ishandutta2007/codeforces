n, m = [int(i) for i in input().split()]
d = set()
for i in range(n):
	_, *a = [int(i) for i in input().split()]
	d |= set(a)

if len(d) == m:
	print("YES")
else:
	print("NO")