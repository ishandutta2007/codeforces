import sys

inp = [x for x in sys.stdin.read().split()]; ii = 0

ttt = int(inp[ii]); ii += 1
for _ in range(ttt):
	b = inp[ii]; ii += 1
	a = ""
	a += b[0]
	for i in range(1, len(b), 2):
		a += b[i]
	print(a)