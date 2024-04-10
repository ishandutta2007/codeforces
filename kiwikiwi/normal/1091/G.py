from random import *
from fractions import gcd
from sys import stdout

n = input()

lst = [n]

def addfactor(x):
	global lst
	while True:
		suc = 0
		for p in lst:
			d = gcd(x,p)
			if d == 1 or d == p:
				continue
			nlst = lst[ : ]
			nlst.remove(p)
			nlst.append(d)
			nlst.append(p / d)
			suc = 1
			break
		if not suc:
			break
		lst = nlst[ : ]

for rd in xrange(50):
	x = randint(1, n - 1)
	d = gcd(x, n)
	if d != 1:
		addfactor(d)
		continue
	stdout.write('sqrt %d\n' % (x * x % n))
	stdout.flush()
	y = input()
	addfactor(gcd(x + y, n))
	addfactor(gcd(x - y, n))

print "!", len(lst),

for p in lst:
	print p,