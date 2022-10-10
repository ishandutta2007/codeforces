import sys

inp = [x for x in sys.stdin.read().split()]; ii = 0

ttt = int(inp[ii]); ii += 1
res = []
for _ in range(ttt):
	n = int(inp[ii]); ii += 1
	a = inp[ii: ii + n]; ii += n
	ok = True
	for i in range(n - 2, -1, -1):
		for j in range(n - 2, -1, -1):
			if a[i][j] == '1' and a[i + 1][j] == '0' and a[i][j + 1] == '0':
				ok = False
				break
		if not ok:
			break
	res.append("YES" if ok else "NO")
print("\n".join(str(x) for x in res))