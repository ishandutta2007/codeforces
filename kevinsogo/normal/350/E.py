from collections import defaultdict
n, m, k = map(int, raw_input().strip().split())

a = map(int, raw_input().strip().split())

sa = set(a)

ns = [v for v in xrange(1,n+1) if v not in sa]
v0 = [v for v in xrange(1,n+1) if v != a[0]]
if k == n or (n-1)*(n-2)/2+(n-k) < m:
	print "-1"
else:
	edges = (
		[(v0[i], v0[j]) for i in xrange(n-1) for j in xrange(i)] + 
		[(a[0], ns[i]) for i in xrange(len(ns))]
	)
	predge = []
	p = defaultdict(lambda: -1)
	def find(n):
		if p[n] < 0:
			return n
		pt = find(p[n])
		p[n] = pt
		return pt
	for a, b in edges:
		fa = find(a)
		fb = find(b)
		if fa != fb:
			if p[fa] == p[fb]:
				p[fb] -= 1
			if p[fa] > p[fb]:
				p[fa] = fb
			else:
				p[fb] = fa
			predge.append((a, b))

	spredge = set(predge)
	predge += [x for x in edges if x not in spredge]
	ct = 0
	for a, b in predge:
		ct += 1
		if ct > m: break
		print a, b