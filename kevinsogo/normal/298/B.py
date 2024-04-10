from sys import *

t, sx, sy, ex, ey = map(int, raw_input().split(" "))
s = raw_input()

from collections import *
v = defaultdict(list)


for i, c in enumerate(s):
	v[c].append(i)

ans = -1
valid = True
if valid and sx < ex:
	df = ex - sx
	if len(v['E']) < df:
		valid = False
	else:
		ans = max(ans, v['E'][df - 1])

if valid and sx > ex:
	df = sx - ex
	if len(v['W']) < df:
		valid = False
	else:
		ans = max(ans, v['W'][df - 1])

if valid and sy < ey:
	df = ey - sy
	if len(v['N']) < df:
		valid = False
	else:
		ans = max(ans, v['N'][df - 1])

if valid and sy > ey:
	df = sy - ey
	if len(v['S']) < df:
		valid = False
	else:
		ans = max(ans, v['S'][df - 1])

if valid:
	print ans + 1
else:
	print -1