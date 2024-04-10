a, b = input().split('e')
a = a[:1]+a[2:]
b = int(b)
a += '0' * 200
a = a[:b+1] + '.' + a[b+1:]
while a[-1] == '0':
	a = a[:-1]
if a[-1] == '.':
	a = a[:-1]
print(a)