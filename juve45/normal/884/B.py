n, k = map(int, raw_input().split())
a = list(map(int, raw_input().split()))

if k == sum(a) + n - 1:
	print 'YES'
else:
	print 'NO'