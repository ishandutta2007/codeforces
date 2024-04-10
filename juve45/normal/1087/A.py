s = raw_input()

if len(s) % 2 == 0:
	s = s[::-1]
s = '%' + s

ans = ''
ind = 1
for i in range(1, len(s)):
	ans += s[ind]
	ind *= -1
	if ind > 0:
		ind += 1

# print ans
print ans[::-1]