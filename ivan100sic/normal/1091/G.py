import sys, random

def kr(s):
	print('sqrt {}'.format(s))
	sys.stdout.flush()
	return int(input())

def gcd(a, b):
	if b == 0:
		return a
	while a % b != 0:
		a, b = b, a % b
	return b

def fct(n):
	good = [n]
	for j in range(30):
		p = int(random.random() * n)
		if p <= 0 or p >= n:
			continue
		q = kr(p*p % n)
		if p == q or p == n - q or p == 0:
			continue
		good += [gcd(abs(p-q), n)]

	factors = [n]

	for x in good:
		if x == 1:
			continue
		tmp = []
		for y in factors:
			if y == x:
				tmp += [y]
			elif y % x == 0:
				tmp += [x, y // x]
			elif x % y == 0:
				tmp += [y]
			else:
				g = gcd(x, y)
				if g == 1 or g == y:
					tmp += [y]
				else:
					tmp += [g, y // g]
		factors = list(set(tmp))

	return list(factors)

n = int(input())
v = fct(n)
w = '!'
w += ' ' + str(len(v))
for x in v:
	w += ' ' + str(x)
print(w)
sys.stdout.flush()