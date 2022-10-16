s = input().split()

nrpoz = 0
nrneg = 0

for i in s:
	if i == '+':
		nrpoz += 1 
	if i == '-':
		nrneg += 1

if s[0] == '?':
	nrpoz += 1

n = int(s[-1])
# print(nrpoz, nrneg, n)

if nrpoz * n - nrneg >= n >= nrpoz - nrneg * n:
	print('Possible')
else:
	print('Impossible')
	exit(0)

neg = []
poz = []

if nrpoz - nrneg > n:
	#toate pozitive o sa fie 1
	#negativele tre sa aiba suma nrpoz - n;
	poz = [1] * nrpoz;
	neg = [1] * nrneg;
	sn = nrneg;
	for i in range(len(neg)):
		if sn < nrpoz - n:
			neg[i] += min(nrpoz - n -sn, n - neg[i])
			sn += neg[i] - 1
else:
	neg = [1] * nrneg
	poz = [1] * nrpoz
	sp = nrpoz - nrneg;
	for i in range(len(poz)):
		if sp < n:
			poz[i] += min(n - poz[i], n - sp)
			sp += poz[i] - 1

sgn = '+'
ipoz, ineg = 0, 0
for i in s:
	if i == '?':
		if sgn == '+':
			print(poz[ipoz], end = ' ')
			ipoz += 1
		else:
			print(neg[ineg], end = ' ')
			ineg += 1
	else:
		sgn = i
		print(i, end = ' ')