import sys
from types import GeneratorType
 
g = []
d = []
n = 0	
 
inp = list(sys.stdin)


def dfs_from_hell():
	st = [[], [0, 0, 0, -1, 0, 0]]
	while len(st) > 1:
		if len(st[-1]) == 7:
			if st[-1][-1] > st[-1][1]:
				st[-1][2] = st[-1][1]
				st[-1][1] = st[-1][-1]
			elif st[-1][-1] > st[-1][2]:
				st[-1][2] = st[-1][-1]
			del st[-1][-1]
			continue
		if len(g[st[-1][0]]) == st[-1][5]:
			i = min(st[-1][1], st[-1][2]) - 1
			if i >= 0:
				d[i] = max(d[i], st[-1][1] + st[-1][2] - 2 * st[-1][4] + 1)
			st[-2].append(st[-1][1])
			del st[-1]
			continue
		if g[st[-1][0]][st[-1][5]] == st[-1][3]:
			st[-1][5] += 1
			continue
		st.append([g[st[-1][0]][st[-1][5]], st[-1][4] + 1, st[-1][4] + 1, st[-1][0], st[-1][4] + 1, 0])
		st[-2][5] += 1
	return st[0][0]


ci = 1
def solve():
	global n, g, d, ci
	n = int(inp[ci])
	ci += 1
	g = [[] for _ in range(n)]
	d = [0 for _ in range(n)]
	
	for i in range(n - 1):
		a, b = map(int, inp[ci].split())
		ci += 1
		a -= 1
		b -= 1
		g[a].append(b);
		g[b].append(a);
	
	m_ans = dfs_from_hell()
	for i in range(n - 2, -1, -1):
		 d[i] = max(d[i], d[i + 1])
	
	ans = 0
	res = []
	for k in range(1, n + 1):
		while ans < m_ans and d[ans] // 2 + k > ans:
			ans += 1
		res.append(str(ans))
	print(' '.join(res))


for _ in range(int(inp[0])):
	solve()