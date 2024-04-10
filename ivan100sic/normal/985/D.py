def bst(n):
	l = 0
	r = 10**44
	o = 0

	if n <= 0:
		return 0

	while l <= r:
		m = (l+r) // 2
		if m*(m+1) // 2 >= n:
			o = m
			r = m-1
		else:
			l = m+1
	return o

def asc(x0, m):
	return x0*m + m*(m-1) // 2

def fitt(m, h):
	if m <= h:
		return m*(m+1) // 2

	y = (m+h) // 2
	x = (m-h) // 2 + 1

	return asc(h, x) + asc(1, m-x)

def resi():
	n, h = map(int, input().split())
	t = bst(n)

	if t <= h:
		return t

	l = 0
	r = 10**44
	sol = r

	while l <= r:
		m = (l+r) // 2

		if fitt(m, h) >= n:
			sol = m
			r = m-1
		else:
			l = m+1

	return sol

print(resi())