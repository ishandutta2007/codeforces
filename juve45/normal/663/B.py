y = 1989
l = [0]
pref = [0] * 12
for i in range(1,10):
	l.append(y)
	pref[i] = str(y)[:-i]
	p = 10 ** i
	y += p;

# print(l)
# print(pref)

n = input()

for i in range(n):
	s = raw_input()
	s = s.split("'")[-1];
	# print(s)
	cand = pref[len(s)] + s
	if int(cand) >= l[len(s)]:
		print cand
	else:
		# print(pref[len(s)])
		cand = '1' + s
		if len(pref[len(s)]) > 0:
			cand = str(int(pref[len(s)]) + 1) + s
		print cand