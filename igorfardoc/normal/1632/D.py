from math import gcd


n = int(input())
a = list(map(int, input().split()))


t = [0] * (4 * n)
def build(v, tl, tr):
	global t
	if tl == tr - 1:
		t[v] = a[tl]
	else:
		tm = (tl + tr) // 2
		build(2*v + 1, tl, tm)
		build(2*v + 2, tm, tr)
		t[v] = gcd(t[2*v + 1], t[2*v + 2])


def query(v, tl, tr, l, r):
	if l >= r:
		return 0
	if tl == l and tr == r:
		return t[v]
	tm = (tl + tr) // 2
	r1 = query(2*v + 1, tl, tm, l, min(tm, r))
	r2 = query(2*v + 2, tm, tr, max(l, tm), r)
	return gcd(r1, r2)


build(0, 0, n)
cur_l = 0
ans = 0
res = []
for i in range(n):
	while query(0, 0, n, cur_l, i + 1) < i + 1 - cur_l:
		cur_l += 1
 
	if query(0, 0, n, cur_l, i + 1) == i + 1 - cur_l:
		ans += 1
		cur_l = i + 1
	res.append(ans)
	
print(' '.join(map(str, res)))