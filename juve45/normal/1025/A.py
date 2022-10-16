n = input()
s = input()
d = dict()
for a in s:
	if a not in d:
		d[a] = 1
	else:
		d[a] = d[a] + 1

for e in d:
	if d[e] > 1:
		print('Yes')
		exit(0)

if len(d) == 1:
	print('Yes')
	exit(0)

print('No')