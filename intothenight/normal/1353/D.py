import sys
import heapq as hq

inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0
qqq = inp[ii]; ii += 1
for _ in range(qqq):
	n = inp[ii]; ii += 1
	a = [[-n, 0]]
	res = [None] * n
	for it in range(n):
		l, i = hq.heappop(a)
		l = -l
		res[i + (l - 1) // 2] = it + 1
		if l > 2:
			hq.heappush(a, [-((l - 1) // 2), i])
		if l > 1:
			hq.heappush(a, [-(l // 2), i + (l + 1) // 2]);
	print(" ".join(str(x) for x in res))