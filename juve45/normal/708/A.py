s = input()
full = 0
started = 0

ans = ''

for l in s:
	if l != 'a' and full == 0:
		ans += chr(ord(l) - 1)
		started = 1
	else:
		if l == 'a' and started == 1:
			full = 1
		ans += l

if ans != s:
	print(ans)
else:
	print(s[:-1] + 'z')