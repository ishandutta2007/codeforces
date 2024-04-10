import sys

inp = [x for x in sys.stdin.read().split()]; ii = 0

ttt = int(inp[ii]); ii += 1
for _ in range(ttt):
	n, k, s = int(inp[ii]), int(inp[ii + 1]), inp[ii + 2]; ii += 3
	cnt = [0] * 26
	for c in s:
		cnt[ord(c) - ord('a')] += 1
	res = 1
	for d in range(1, k + 1):
		if k % d == 0:
			for l in range(d, n + 1, d):
				q = l // d
				counter = 0
				for x in cnt:
					counter += x // q
				if counter >= d:
					res = max(res, l)
	print(res)