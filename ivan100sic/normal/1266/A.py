t = int(input())
for i in range(t):
	a = input()
	b = [0] * 10
	c = [0] * 2
	for x in a:
		d = int(x)
		b[d] += 1
		c[d % 2] += 1
	if int(a) % 3 == 0 and b[0] > 0 and c[0] > 1:
		print('red')
	else:
		print('cyan')