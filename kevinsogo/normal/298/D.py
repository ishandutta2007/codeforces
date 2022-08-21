n, m, k = map(int, raw_input().split())
ns = sorted(map(int, raw_input().split()))
ms = sorted(map(int, raw_input().split()))
nt = []
mt = []
nl = len(ns)
ml = len(ms)
ni = mi = 0
while ni < nl and mi < ml:
	if ns[ni] < ms[mi]:
		nt.append(ns[ni])
		ni += 1
	elif ns[ni] > ms[mi]:
		mt.append(ms[mi])
		mi += 1
	else:
		ni += 1
		mi += 1
while ni < nl:
	nt.append(ns[ni])
	ni += 1
while mi < ml:
	mt.append(ms[mi])
	mi += 1
ns = nt
ms = mt
nl = len(ns)
ml = len(ms)
ni = nl - 1
mi = ml - 1
succ = False
while ni >= 0 and mi >= 0:
	if ns[ni] > ms[mi]:
		succ = True
		break
	ni -= 1
	mi -= 1
if ni >= 0:
	succ = True
print 'YES' if succ else 'NO'