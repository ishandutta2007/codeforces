import sys

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

ttt = inp[ii]; ii += 1
res = []
for _ in range(ttt):
	a, b = inp[ii: ii + 2]; ii += 2
	res.append(max(2 * min(a, b), max(a, b)) ** 2)
print("\n".join(str(x) for x in res))