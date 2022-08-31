s = raw_input()

part = {}
part['1'] = '8'
part['2'] = '7'
part['3'] = '6'
part['4'] = '5'
part['5'] = '4'
part['6'] = '3'
part['7'] = '2'
part['8'] = '1'

n = len(s)

ans = 1
i = 0
while i < n:
	if s[i] != '9':
		ln = 1
		while i + 1 < n and part[s[i]] == s[i + 1]:
			ln += 1
			i += 1
		if ln & 1:
			ln += 1
			ln >>= 1
			ans *= ln

	i += 1

print ans