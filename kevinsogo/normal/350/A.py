n, m = map(int, raw_input().strip().split())

ns = map(int, raw_input().strip().split())
ms = map(int, raw_input().strip().split())

ns.sort()

ns[0] *= 2

v = max(ns)
if v < min(ms):
	print v
else:
	print -1