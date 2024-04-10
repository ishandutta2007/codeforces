input()

s1 = input()
s2 = input()

if '*' not in s1:
	if s1 == s2:
		print('YES')
	else:
		print('NO')
	exit(0)

s11, s12 = s1.split('*')

# print('[' + s11 + ']', '[' + s12 + ']')

# print(s2[-len(s12):])
if len(s2) >= len(s11) + len(s12) and (len(s11) == 0 or s11 == s2[:len(s11)]) and (len(s12) == 0 or s12 == s2[-len(s12):]):
	print('YES')
else:
	print("NO")