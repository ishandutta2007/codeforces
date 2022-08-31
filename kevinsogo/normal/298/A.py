from sys import *

n = int(raw_input())
s = raw_input()

minR = n + 1
maxR = 0
minL = n + 1
maxL = 0

for i, v in enumerate(s):
	if v == 'L':
		minL = min(minL, i)
		maxL = max(maxL, i)
	if v == 'R':
		minR = min(minR, i)
		maxR = max(maxR, i)

if minR <= maxR:
	print "%d %d" % (minR + 1, maxR + 2)
else:
	print "%d %d" % (maxL + 1, minL)