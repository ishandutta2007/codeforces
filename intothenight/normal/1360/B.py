import sys

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

ttt = inp[ii]; ii += 1
res = []
for _ in range(ttt):
	n = inp[ii]; ii += 1
	a = sorted(inp[ii: ii + n]); ii += n
	c = 10000
	for i in range(n - 1):
		c = min(c, abs(a[i] - a[i + 1]))
	res.append(c)
print("\n".join(str(x) for x in res))