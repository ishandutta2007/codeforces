n,m = map(int, raw_input().split())


s = ['', '', '', '']
s[0] = '#' * m
s[1] = '.' * (m-1) + '#'
s[2] = '#' * m
s[3] = '#' + '.' * (m-1)

for i in range(n):
	print s[i % 4]