import sys

inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0
qqq = inp[ii]; ii += 1
for _ in range(qqq):
	n = inp[ii]; ii += 1
	m = n // 2
	print(m * (m + 1) * (2 * m + 1) * 4 // 3)