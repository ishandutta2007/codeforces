import sys

inp = [x for x in sys.stdin.read().split()]; ii = 0

ttt = int(inp[ii]); ii += 1
res = []
for _ in range(ttt):
	n, m = int(inp[ii]), int(inp[ii + 1]); ii += 2
	a = inp[ii: ii + n]; ii += n
	cur = ""
	ok = False
	for p in range(m):
		for c in range(ord('a'), ord('z') + 1):
			s = "".join([chr(c) if p == j else a[0][j] for j in range(m)])
			if all([(sum(s[j] != x[j] for j in range(m)) <= 1) for x in a]):
				cur = s
				ok = True;
				break;
		if ok:
			break
	res.append(cur if ok else "-1")
print("\n".join(str(x) for x in res))