n = int(input())
d = '/'

def r(s):
	e = s.split('/')
	f = []
	for g in e:
		if g == '..':
			f = f[:-1]
		else:
			f += [g]
	return '/'.join(f) + '/'

for i in range(n):
	a = input()
	if len(a.split()) == 2:
		b, c = a.split()
		if c[0] == '/':
			d = r(c)
		else:
			d = r(d + c)
	else:
		print(d)