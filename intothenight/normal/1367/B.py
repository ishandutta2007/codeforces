import sys

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

ttt = inp[ii]; ii += 1
for _ in range(ttt):
	cnt = [0] * 2
	n = inp[ii]; ii += 1
	for i in range(n):
		x = inp[ii]; ii += 1
		if x % 2 != i % 2:
			cnt[i % 2] += 1;
	print(cnt[0] if cnt[0] == cnt[1] else -1)