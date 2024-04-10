import sys

inp = [x for x in sys.stdin.read().split()]; ii = 0

ttt = int(inp[ii]); ii += 1
for _ in range(ttt):
	s, m = inp[ii], int(inp[ii + 1]); ii += 2
	b = [int(x) for x in inp[ii: ii + m]]; ii += m
	cnt = [0] * 26
	for c in s:
		cnt[ord(c) - ord('a')] += 1
	res = [-1] * m
	for c in range(25, -1, -1):
		cur_ind = []
		for i in range(m):
			if res[i] == -1:
				cur_sum = 0
				for j in range(m):
					if res[j] != -1:
						cur_sum += abs(i - j)
				if cur_sum == b[i]:
					cur_ind.append(i)
		if len(cur_ind) <= cnt[c]:
			for i in cur_ind:
				res[i] = c
	print("".join(chr(c + ord('a')) for c in res))