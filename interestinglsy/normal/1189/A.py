n = input()
s = input().strip()
cnt0 = s.count('0')
cnt1 = s.count('1')

if cnt0 != cnt1:
	print(1)
	print(s)
else:
	print(2)
	print(s[0],s[1:])