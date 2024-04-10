import sys

inp = [x for x in sys.stdin.read().split()]; ii = 0

ttt = int(inp[ii]); ii += 1
for _ in range(ttt):
	n, k = int(inp[ii]), int(inp[ii + 1]); ii += 2
	s = inp[ii]; ii += 1
	pos = [-k - 1]
	for i in range(n):
		if s[i] == '1':
			pos.append(i)
	pos.append(n + k)
	res = 0
	for i in range(len(pos) - 1):
		if pos[i + 1] - pos[i] >= 2 * k + 2:
			res += (pos[i + 1] - pos[i]) // (k + 1) - 1
	print(res)