n = int(input())
s = hex(n)
x = 0
for c in s[2:]:
	if c == '0':
		x += 1
	if c == '4':
		x += 1
	if c == '6':
		x += 1
	if c == '8':
		x += 2
	if c == '9':
		x += 1
	if c == 'a':
		x += 1
	if c == 'b':
		x += 2
	if c == 'd':
		x += 1
print(x)