import sys

inp = [x for x in sys.stdin.read().split()]; ii = 0

ttt = int(inp[ii]); ii += 1
for _ in range(ttt):
	n = int(inp[ii]); ii += 1
	s = inp[ii]; ii += 1
	b, minb = 0, 0
	for c in s:
		if c == '(':
			b += 1
		else:
			b -= 1
		minb = min(minb, b)
	print(-minb)
"""
( ) )  ( )  ( )  (
1 0 -1 0 -1 0 -1 0
"""