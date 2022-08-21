n, x = map(int, raw_input().strip().split())

def test(ta):
	vsa = [0]*len(ga)
	vsb = [0]*len(gb)
	cr = x
	ct = 0
	while True:
		mx = -1
		if ta:
			for i in xrange(len(ga)):
				if not vsa[i] and ga[i][0] <= cr and (mx == -1 or ga[i][1] > ga[mx][1]):
					mx = i
			if mx == -1: break
			ct += 1
			cr += ga[mx][1]
			vsa[mx] = 1
		else:
			for i in xrange(len(gb)):
				if not vsb[i] and gb[i][0] <= cr and (mx == -1 or gb[i][1] > gb[mx][1]):
					mx = i
			if mx == -1: break
			ct += 1
			cr += gb[mx][1]
			vsb[mx] = 1
		ta = not ta
	return ct


g0 = []
g1 = []
for i in xrange(n):
	t, h, m = map(int, raw_input().strip().split())
	if t == 0:
		g0.append((h, m))
	else:
		g1.append((h, m))

ga = sorted(g0)
gb = sorted(g1)

print max(test(True), test(False))