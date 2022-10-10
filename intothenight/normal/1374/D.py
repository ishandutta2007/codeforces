import sys
from collections import defaultdict

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

ttt = inp[ii]; ii += 1
for _ in range(ttt):
	n, k = inp[ii: ii + 2]; ii += 2
	r = defaultdict(lambda: -1)
	r[0] = -1
	for x in inp[ii: ii + n]:
		if x % k:
			if r[x % k] != -1:
				r[x % k] += k
			else:
				r[x % k] = k - x % k
	print(max(r.values()) + 1)
	ii += n