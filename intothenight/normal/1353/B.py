import sys

inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0
qqq = inp[ii]; ii += 1
for _ in range(qqq):
	n, k = inp[ii: ii + 2]; ii += 2
	a = sorted(inp[ii: ii + n]); ii += n
	b = sorted(inp[ii: ii + n]); ii += n
	b.reverse()
	res = sum(a)
	for i in range(k):
		if a[i] >= b[i]:
			break
		else:
			res += b[i] - a[i]
	print(res)