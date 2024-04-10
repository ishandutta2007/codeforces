n = int(raw_input())
length = {'polycarp':1}
for i in xrange(n):
	s = raw_input().split()
	length[s[0].lower()] = length[s[2].lower()] + 1
print max(length.values())