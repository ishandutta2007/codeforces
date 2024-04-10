import sys

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

ttt = inp[ii]; ii += 1
res = []
for _ in range(ttt):
	n = inp[ii]; ii += 1
	a = inp[ii: ii + n]; ii += n
	cnt = [0] * 2
	for x in a:
		cnt[x & 1] += 1
	if cnt[0] % 2 == 0 and cnt[1] % 2 == 0:
		res.append("YES")
	else:
		a = sorted(a)
		ok = False;
		for i in range(n - 1):
			if a[i] + 1 == a[i + 1]:
				ok = True
				break
		if ok:
			res.append("YES")
		else:
			res.append("NO")
print("\n".join(x for x in res))