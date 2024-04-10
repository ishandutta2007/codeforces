n = input()

s = ''
for i in range(n):
	if i % 4 < 2: s += 'a'
	else: s += 'b'
print s