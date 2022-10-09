d = {1: {(2, 13)}}
for j in range(2, 2000):
	d[j] = set()
big = 10**302
for i in range(1, 2000):
	ok = 0
	for a, b in d[i]:
		c = 12*a
		if a <= big:
			ok = 1
		d[i+1].add((b, c))
		c = 13*b - 12*a
		if a <= big:
			ok = 1
		d[i+1].add((b, c))
	if not ok:
		break

n = int(input())
g = set()
for i in range(1, 2000):
	for a, b in d[i]:
		if a == n:
			g.add(i)
if len(g) > 0:
	print('YES')
	print(len(g))
	print(*list(sorted(g)))
	c = []
	for i in g:
		for a, b in d[i]:
			if a != n:
				c += [a]
	c = list(sorted(list(set(c))))
	if len(c) > 1000:
		c = c[:1000]
	print(len(c))
	print(*c)
else:
	print('NO')