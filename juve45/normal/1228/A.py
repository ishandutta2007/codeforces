l, r = map(int, raw_input().split())

def ok(k):
	s = set()
	for i in str(k):
		s.add(i)
	if len(s) == len(str(k)):
		return 1
	return 0

for i in range(l, r + 1):
	if(ok(i)):
		print i
		exit(0)
print -1