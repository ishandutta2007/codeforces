import sys

inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0
qqq = inp[ii]; ii += 1
for _ in range(qqq):
	n, m = inp[ii: ii + 2]; ii += 2
	if n is 1:
		print(0)
	elif n is 2:
		print(m)
	else:
		print(2 * m)