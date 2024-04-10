n = input()
v = map(int,raw_input().strip().split())
z = map(abs,v)
if n & 1:
	print sum(z)
else:
	w = [-x for x in v if x <= 0]
	if len(w) & 1:
		print sum(z) - min(z)*2
	else:
		print sum(z)