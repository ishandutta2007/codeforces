import sys

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

ttt = inp[ii]; ii += 1
for _ in range(ttt):
	x, y, n = inp[ii: ii + 3]; ii += 3
	rem = y % x
	print((n - rem) // x * x + rem)