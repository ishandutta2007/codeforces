import sys

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n, k = inp[ii: ii + 2]; ii += 2
both, a, b = [], [], []
for i in range(n):
	x, p, q = inp[ii: ii + 3]; ii += 3
	if p and q:
		both.append(x)
	elif p:
		a.append(x)
	elif q:
		b.append(x)
if len(both) + len(a) < k or len(both) + len(b) < k:
	print(-1)
else:
	res = 2 * 10**9
	both.sort(); a.sort(); b.sort()
	cnt, tot, i, j = len(both), sum(both[0: min(len(both), k)]), 0, 0
	for cnt in range(min(len(both), k), max(k - min(len(a), len(b)), 0) - 1, -1):
		while i < k - cnt:
			tot += a[i]
			i += 1
		while j < k - cnt:
			tot += b[j]
			j += 1
		res = min(res, tot)
		if cnt > 0:
			tot -= both[cnt - 1]
	print(res)