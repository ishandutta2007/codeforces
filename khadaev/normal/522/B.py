n = int(raw_input())
w, h = [], []
for i in xrange(n):
	str = raw_input().split()
	w.append(int(str[0]))
	h.append(int(str[1]))
s = sum(w)
m = max(h)
if h.count(m) > 1:
	for i in xrange(n):
		print (s - w[i]) * m,
else:
	m1 = max([i for i in h if i != m])
	for i in xrange(n):
		if h[i] == m:
			print (s - w[i]) * m1,
		else:
			print (s - w[i]) * m,