def gcd(x, y):
	if y == 0:
		return x
	return gcd(y, x % y)
x, y = map(int, input().split())
if gcd(x, y) != 1:
	print('Impossible')
	exit()
a = []
while y != 1:
	a += [x // y]
	x %= y
	x, y = y, x
a += [x-1]
s = 'A'
for x in a:
	if x > 0:
		print(x, end=s)
	s = 'AB'.replace(s, '')