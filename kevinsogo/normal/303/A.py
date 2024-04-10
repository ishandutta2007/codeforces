n = input()
if n == 1:
	print 0
	print 0
	print 0
elif n & 1:
	print ' '.join(str(x) for x in xrange(n))
	print ' '.join(str(x) for x in xrange(1, n)), '0'
	print ' '.join(str((x * 2 +1 ) % n) for x in xrange(n))
else:
	print -1