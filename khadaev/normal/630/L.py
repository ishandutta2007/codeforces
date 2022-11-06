s = raw_input()
n = int(s[1]) + int(s[3]) * 10 + int(s[4]) * 100 + int(s[2]) * 1000 + int(s[0]) * 10000
d = 0
p = 1
k = n ** 5 % 100000
if (k == 0):
	print "00000"
else:
	while (p <= k):
		p *= 10
		d += 1
	s = ""
	for i in range(5 - d): s += '0'
	print s + str(k)