import sys

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

ttt = int(inp[ii]); ii += 1
res = []
for _ in range(ttt):
	n, m, a, b = inp[ii: ii + 4]; ii += 4
	if n * a == m * b:
		res.append("YES")
		for i in range(n):
			c = [0] * m
			for j in range(a):
				c[(i * a + j) % m] = 1
			res.append("".join(str(x) for x in c))
	else:
		res.append("NO")
print("\n".join(str(x) for x in res))