qqq = int(input())
ans = []
for _ in range(qqq):
	n, k = [int(x) for x in input().split()]
	s = [c - b'0'[0] for c in input().encode('ascii')]
	res = 10**9
	tot = sum(int(x) for x in s)
	for rem in range(k):
		c = s[rem: n: k]
		m = len(c)
		cnt = sum(c)
		dp = [[0, 0, 0]]
		for x in c:
			if not x:
				dp.append([dp[-1][0], min(dp[-1][0], dp[-1][1]) + 1, min(dp[-1])])
			else:
				dp.append([dp[-1][0] + 1, min(dp[-1][0], dp[-1][1]), min(dp[-1]) + 1])
		res = min(res, tot - cnt + min(dp[-1]))
	ans.append(res)
print("\n".join(str(x) for x in ans))