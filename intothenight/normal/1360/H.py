import sys

inp = [x for x in sys.stdin.read().split()]; ii = 0

ttt = int(inp[ii]); ii += 1
res = []
for _ in range(ttt):
	n, m = int(inp[ii]), int(inp[ii + 1]); ii += 2
	a = []
	for _ in range(n):
		temp = inp[ii]; ii += 1
		x = 0
		for i in range(m):
			if temp[i] == '1':
				x += 1 << m - 1 - i
		a.append(x)
	t = ((1 << m) - n - 1) // 2
	low, high = 0, 1 << m
	while high - low > 1:
		mid = low + high >> 1
		if mid - sum([x < mid for x in a]) <= t:
			low = mid
		else:
			high = mid
	res.append("".join(str(int(not not low & 1 << i)) for i in range(m - 1, -1, -1)))
print("\n".join(str(x) for x in res))