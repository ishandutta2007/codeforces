import sys

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

ttt = inp[ii]; ii += 1
for _ in range(ttt):
	n = inp[ii]; ii += 1
	e2, e3 = 0, 0
	while n % 2 == 0:
		n /= 2
		e2 += 1
	while n % 3 == 0:
		n /= 3
		e3 += 1
	if n > 1 or e2 > e3:
		print(-1)
	else:
		print(e3 - e2 + e3)