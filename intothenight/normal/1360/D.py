import sys

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

ttt = inp[ii]; ii += 1
res = []
for _ in range(ttt):
	n, k = inp[ii: ii + 2]; ii += 2
	i = 1
	c = 0
	while i <= k and i <= n:
		d = n // (n // i)
		if d <= k and n % d == 0:
			c = d
		i = d + 1
	res.append(n // c)
print("\n".join(str(x) for x in res))