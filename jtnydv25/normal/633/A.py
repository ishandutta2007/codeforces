import sys
a, b, c = map(int, raw_input().split())
for x in range(0, 10001):
	if (a * x <= c) and ((c - a * x) % b == 0):
		print "Yes"
		sys.exit()
print "No"