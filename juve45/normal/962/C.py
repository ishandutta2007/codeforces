n = raw_input()

def diff(a, b):
	a = list(str(a))
	b = list(str(b))
	if len(a) > len(b):
		return 100000
	j = 0
	for i in a:
		while j < len(b) and b[j] != i:
			j+=1
		if j < len(b) and b[j] == i:
			j+=1
		else:
			return 10000
	return len(b) - len(a)

ans = -1
dans = 10000

for i in range(1, 50000):
	d = diff(i * i, n)
	if d < dans:
		dans = d
		ans = i

if dans > 111:
	dans = -1

print dans